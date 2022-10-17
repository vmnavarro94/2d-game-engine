//
//  Tile.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-16.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include "ResourceAllocator.hpp"

struct TileInfo {
    TileInfo() : tileId(-1) {}
    TileInfo(int textureId, unsigned int tileId, sf::IntRect textureRect)
        : textureId(textureId), tileId(tileId), textureRect(textureRect) {}
    int tileId;
    int textureId;
    sf::IntRect textureRect;
};

struct Tile {
    std::shared_ptr<TileInfo> properties;
    int x;
    int y;
};

#endif /* Tile_hpp */
