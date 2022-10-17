//
//  TileMapParser.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-16.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "TileMapParser.hpp"
#include <iostream>

TileMapParser::TileMapParser(ResourceAllocator<sf::Texture>& textureAllocator)
    : textureAllocator(textureAllocator) {}

std::vector<std::shared_ptr<Object>> TileMapParser::parse(const std::string& file, sf::Vector2i offset)
{
    char* fileLoc = new char[file.size() + 1];
    //TODO: make multi format version of string copy
    #ifdef MACOS
        strlcpy(fileLoc, file.c_str(), file.size() + 1);
    #else
        strcpy_s(fileLoc, file.size() + 1, file.c_str());
    #endif
    
    //TODO: error checking - check file exists before attempting open.
    rapidxml::file<> xmlFile(fileLoc);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>* rootNode = doc.first_node("map");
    
    std::shared_ptr<MapTiles> tiles = buildMapTiles(rootNode);
    
    int tileSizeX = std::atoi(rootNode->first_attribute("tilewidth")->value());
    int tileSizeY = std::atoi(rootNode->first_attribute("tileheight")->value());
    int mapsizeX = std::atoi(rootNode->first_attribute("width")->value());
    int mapsizeY = std::atoi(rootNode->first_attribute("height")->value());
    
    std::vector<std::shared_ptr<Object>> tileObjects;
    
    for (const auto& layer : *tiles)
    {
        for (const auto& tile : *layer.second)
        {
            std::shared_ptr<TileInfo> tileInfo = tile->properties;
            
            std::shared_ptr<Object> tileObject = std::make_shared<Object>();
           
            const unsigned int tileScale = 3;
            
            auto sprite = tileObject->addComponent<CSprite>();
            sprite->setTextureAllocator(&textureAllocator);
            sprite->load(tileInfo->textureId);
            sprite->setTextureRect(tileInfo->textureRect);
            sprite->setScale(tileScale, tileScale);
            
            float x = (tile->x * tileSizeX * (int)tileScale) + offset.x;
            float y = tile->y * tileSizeY * (int)tileScale + offset.y;
            tileObject->transform->setPosition(x, y);
            
            tileObjects.emplace_back(tileObject);
        }
    }
    
    return tileObjects;
}

std::shared_ptr<MapTiles> TileMapParser::buildMapTiles(xml_node<> *rootNode) {
    std::shared_ptr<TileSheetData> tileSheetData = buildTileSheetData(rootNode);
    std::shared_ptr<MapTiles> map = std::make_shared<MapTiles>();
    
    //Loop through each layer in the xml
    for(xml_node<>* node = rootNode->first_node("layer"); node; node = node->next_sibling()) {
        std::pair<std::string, std::shared_ptr<Layer>> mapLayer = buildLayer(node, tileSheetData);
        map->emplace(mapLayer);
    }
    return map;
}

std::shared_ptr<TileSheetData> TileMapParser::buildTileSheetData(xml_node<> *rootNode) {
    TileSheetData tileSheetData;
    //Traverse to the tile set node
    xml_node<>* tileSheetNode = rootNode->first_node("tileset");
    //TODO: add error checking to ensure these values exist
    //TODO: add support for multiple tile sets
    
    int firstId = std::atoi(tileSheetNode->first_attribute("firstgrid")->value());
    //Build tile set data
    tileSheetData.tileSize.x = std::atoi(tileSheetNode->first_attribute("tilewidth")->value());
    tileSheetData.tileSize.y = std::atoi(tileSheetNode->first_attribute("tileheight")->value());
    int tileCount = std::atoi(tileSheetNode->first_attribute("tilecount")->value());
    tileSheetData.columns = std::atoi(tileSheetNode->first_attribute("columns")->value());
    tileSheetData.rows = tileCount / tileSheetData.columns;
    
    xml_node<>* imageNode = tileSheetNode->first_node("image");
    tileSheetData.textureId = textureAllocator.add(std::string(imageNode->first_attribute("source")->value()));

    //TODO: add error checking - output a message if texture not found
    tileSheetData.imageSize.x = std::atoi(imageNode->first_attribute("width")->value());
    tileSheetData.imageSize.y = std::atoi(imageNode->first_attribute("height")->value());
    
    return std::make_shared<TileSheetData>(tileSheetData);
}

std::pair<std::string, std::shared_ptr<Layer>> TileMapParser::buildLayer(xml_node<> *layerNode, std::shared_ptr<TileSheetData> tileSheetData) {
    TileSet tileSet;
    std::shared_ptr<Layer> layer = std::make_shared<Layer>();
    
    int width = std::atoi(layerNode->first_attribute("width")->value());
    int height = std::atoi(layerNode->first_attribute("height")->value());
    xml_node<>* dataNode = layerNode->first_node("data");
    
    char* mapIndices = dataNode->value();
    std::stringstream fileStream(mapIndices);
    int count = 0;
    std::string line;
    while(fileStream.good()) {
        std::string substr;
        std::getline(fileStream, substr, ',');
        if (!Utilities::isInteger(substr)) {
            //Remoce special characters from the int before parsing
            substr.erase(std::remove(substr.begin(), substr.end(), '\r'), substr.end());
            substr.erase(std::remove(substr.begin(), substr.end(), '\n'), substr.end());
            //TODO: add check to confirm the character removals worked
        }
        int tileId = std::stoi(substr);
        if (tileId != 0) {
            auto itr = tileSet.find(tileId);
            if (itr == tileSet.end()) {
                int textureX = tileId % tileSheetData->columns - 1;
                int textureY = tileId / tileSheetData->columns;
                std::shared_ptr<TileInfo> tileInfo = std::make_shared<TileInfo>(
                    tileSheetData->textureId, tileId, sf::IntRect(
                                            textureX * tileSheetData->tileSize.x,
                                            textureY * tileSheetData->tileSize.y,
                                            tileSheetData->tileSize.x,
                                            tileSheetData->tileSize.y));
                itr = tileSet.insert(std::make_pair(tileId, tileInfo)).first;
            }
            std::shared_ptr<Tile> tile = std::make_shared<Tile>();
            //Bind properties of tile form a set.
            tile->properties = itr->second;
            tile->x = count % width - 1;
            tile->y = count / width;
            layer->emplace_back(tile);
        }
        count++;
    }
    const std::string layerName = layerNode->first_attribute("name")->value();
    return std::make_pair(layerName, layer);
}
