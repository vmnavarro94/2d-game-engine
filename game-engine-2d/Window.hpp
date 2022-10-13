//
//  Window.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp
#include <SFML/Graphics.hpp>
class Window
{
public:
    Window(const std::string& windowName);
    void update();
    void beginDraw();
    void draw(const sf::Drawable& drawable);
    void endDraw();
    bool isOpen() const;
private:
    sf::RenderWindow window;
};
#endif /* Window_hpp */
