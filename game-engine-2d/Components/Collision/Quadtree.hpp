//
//  Quadtree.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-24.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Quadtree_hpp
#define Quadtree_hpp

#include <memory>
#include <vector>
#include "CBoxCollider.hpp"
#include "Object.hpp"
#include "Debug.hpp"

//Adaptation of this quadtree: https://github.com/ryanp102694/java-simple-quadtree

class Quadtree {
public:
    Quadtree();
    Quadtree(int maxObjects, int maxLevels, int level,
             sf::FloatRect bounds, Quadtree* parent);
    //inserts object into quadtree
    void insert(std::shared_ptr<CBoxCollider> object);
    //removes object from quadtree when it is no longer need it to collide
    void remove(std::shared_ptr<CBoxCollider> object);
    //removes all objects from tree
    void clear();
    //returns vector of colliders that intersects with the search area
    std::vector<std::shared_ptr<CBoxCollider>> search(const sf::FloatRect& area);
    //returns the bounds of this node
    const sf::FloatRect& getBounds() const;
    void drawDebug();
    
private:
    void search(const sf::FloatRect& area,
                std::vector<std::shared_ptr<CBoxCollider>>& overlapingObjects);
    //returns the index for the node that will contain the object
    //-1 is returned if it is this node
    int getChildIndexForObject(const sf::FloatRect& objectBounds);
    //creates the child nodes
    void split();
    
    //indices in the array of children
    static const int thisTree = -1;
    static const int childNE = 0;
    static const int childNW = 1;
    static const int childSW = 2;
    static const int childSE = 3;
    int maxObjects;
    int maxLevels;
    
    //nullptr if this is the base node
    Quadtree* parent;
    std::shared_ptr<Quadtree> children[4];
    //stores objects in this node
    std::vector<std::shared_ptr<CBoxCollider>> objects;
    
    //how deep the current node is from the base node
    //the firts node starts at 0 an then its child is 1 and so on
    int level;
    
    //the bounds of this node
    sf::FloatRect bounds;
};

#endif /* Quadtree_hpp */
