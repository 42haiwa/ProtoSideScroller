#ifndef __BLOCK__H__
#define __BLOCK__H__

#include <SFML/Graphics.hpp>

class Block {
    protected:
        sf::Vector2f m_pos;
        sf::Color m_color;
        sf::RectangleShape m_rectangle;

        static constexpr auto B_SIZE{40.f};

    public:
        Block(sf::Vector2f const & pos, sf::Color const & color);
        virtual void update() = 0;
        virtual void render(sf::RenderWindow & window) const = 0;
};

#endif
