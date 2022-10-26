//
//  Debug.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-26.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Debug_hpp
#define Debug_hpp

#include <array>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Debug {
public:
    static void draw(Window& window);
    static void drawRect(const sf::FloatRect& rect, sf::Color color = sf::Color::White);
    static void drawLine(const sf::Vector2f& from, const sf::Vector2f& to, sf::Color color = sf::Color::White);
    static void log(const std::string& message);
    static void logWarning(const std::string& message);
    static void logError(const std::string& message);
    
private:
    static std::vector<std::array<sf::Vertex, 2>> lines;
    static std::vector<sf::RectangleShape> rects;
};

#endif /* Debug_hpp */
