//
//  Debug.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-26.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Debug.hpp"

std::vector<sf::RectangleShape> Debug::rects = {};
std::vector<std::array<sf::Vertex, 2>> Debug::lines = {};

void Debug::draw(Window &window) {
    for (auto& rect : rects) {
        window.draw(rect);
    }
    rects.clear();
    
    for (auto& line: lines) {
        sf::Vertex newLine[2] = { line.at(0), line.at(1) };
        window.draw(newLine, 2, sf::Lines);
    }
    lines.clear();
}

void Debug::drawRect(const sf::FloatRect &rect, sf::Color color) {
    sf::Vector2f size(rect.width, rect.height);
    sf::Vector2f pos(rect.left, rect.top);
    sf::RectangleShape shape(size);
    
    shape.setPosition(pos);
    shape.setOutlineColor(color);
    shape.setOutlineThickness(3.f);
    shape.setFillColor(sf::Color::Transparent);
    rects.push_back(shape);
}

void Debug::drawLine(const sf::Vector2f &from, const sf::Vector2f &to, sf::Color color) {
    lines.push_back({ sf::Vertex(from, color), sf::Vertex(to, color) });
}

void Debug::log(const std::string &message) {
    std::cout << message << std::endl;
}

void Debug::logWarning(const std::string &message) {
    std::cout << "WARNING: " << message << std::endl;
}

void Debug::logError(const std::string &message) {
    std::cout << "ERROR: " << message << std::endl;
}
