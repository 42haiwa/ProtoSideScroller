#include "Block.h"

Block::Block(sf::Vector2f const & pos, sf::Color const & color) : m_pos{pos}, m_color{color}, m_rectangle{sf::Vector2f{B_SIZE, B_SIZE}} {
    m_rectangle.setFillColor(m_color);
}
