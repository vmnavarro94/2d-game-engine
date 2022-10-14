//
//  ResourceAllocator.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef ResourceAllocator_hpp
#define ResourceAllocator_hpp

#include <map>
#include <string>
#include <memory>

template<typename T>
class ResourceAllocator {
public:
    int add(const std::string& filePath) {
        auto it = resources.find(filePath);
        if (it != resources.end()) {
            return it->second.first;
        }
        std::shared_ptr<T> resource = std::make_shared<T>();
        if (!resource->loadFromFile(filePath)) {
            return -1;
        }
        resources.insert(
                         std::make_pair(filePath, std::make_pair(currentId, resource)));
        return currentId++;
    }
    
    void remove(int id) {
        for (auto it = resources.begin(); it != resources.end; it++) {
            if (it->second.first == id) {
                resources.erase(it->first);
            }
        }
    }
    
    std::shared_ptr<T> get(int id) {
        for (auto it = resources.begin(); it != resources.end(); it++) {
            if (it->second.first == id) {
                return it->second.second;
            }
        }
        return nullptr;
    }
    
    bool has(int id) {
        return (get(id) != nullptr);
    }
    
private:
    int currentId;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

#endif /* ResourceAllocator_hpp */
