//
//  TileMapParser.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-16.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef TileMapParser_hpp
#define TileMapParser_hpp

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <sstream>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Tile.hpp"
#include "Utilities.hpp"
#include "Object.hpp"
#include "CSprite.hpp"
#include "CBoxCollider.hpp"

struct TileSheetData {
    //textureId is retrieved from the textureAllocator
    int textureId;
    sf::Vector2u imageSize; //Size of the complete texture
    int columns;
    int rows;
    sf::Vector2u tileSize; //Size of each individual tile
};

struct Layer {
    std::vector<std::shared_ptr<Tile>> tiles;
    bool isVisible;
};

using namespace rapidxml;
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>;
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;
using TileSheets = std::map<int, std::shared_ptr<TileSheetData>>;

class TileMapParser {
public:
    TileMapParser(ResourceAllocator<sf::Texture>& textureAllocator);
    std::vector<std::shared_ptr<Object>> parse(const std::string& file, sf::Vector2i offset);
    
private:
    std::shared_ptr<TileSheets> buildTileSheetData(xml_node<>* rootNode);
    std::shared_ptr<MapTiles> buildMapTiles(xml_node<>* rootNode);
    std::pair<std::string, std::shared_ptr<Layer>> buildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheets> tileSheets);
    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif /* TileMapParser_hpp */
