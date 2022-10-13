//
//  Window.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Window.hpp"
Window::Window(const std::string& windowName)
: window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
}
void Window::update()
{
    sf::Event event;
    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
void Window::beginDraw()
{
    window.clear(sf::Color::White);
}
void Window::draw(const sf::Drawable& drawable)
{
    window.draw(drawable);
}
void Window::endDraw()
{
    window.display();
}
bool Window::isOpen() const
{
    return window.isOpen();
}
