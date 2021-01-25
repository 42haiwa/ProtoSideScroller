#include "DirtBlock.h"

DirtBlock::DirtBlock(sf::Vector2f const & pos) : Block{pos, sf::Color::Red} {
}

void DirtBlock::update() {
    m_rectangle.setPosition(m_pos);
}

void DirtBlock::render(sf::RenderWindow & window) const {
    window.draw(m_rectangle);
}
