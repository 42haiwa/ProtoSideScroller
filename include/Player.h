#ifndef __PLAYER__H__
#define __PLAYER__H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.h"

class Player {
    private:
        sf::Clock m_clock;
        sf::Clock m_animClock;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_pos;
        sf::RectangleShape m_box;
        sf::Vector2f m_moveSpeed;
        sf::Vector2f m_scale;
        sf::View m_view;
        
        bool m_grounded;
        bool m_spaceKeyReleased;
        int m_jumpCount;

        static constexpr int TEXTURE_POS_X{768 / 8};
        static constexpr float ANIMATION_SPEED{0.5f};
        static constexpr float JUMP_SPEED{-400.f};

    public:
        Player(std::string const & path);
        void update(sf::RenderWindow & window);
        void render(sf::RenderWindow & window) const;
        void checkKeyboard(sf::Time dt, sf::Time animDt);
        void applyGravity(sf::Time dt);
};

#endif
