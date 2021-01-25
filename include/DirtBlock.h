#ifndef __DIRT__BLOCK__
#define __DIRT__BLOCK__

#include <SFML/Graphics.hpp>
#include "Block.h"

class DirtBlock : public Block {
    public:
        DirtBlock(sf::Vector2f const & pos);
        void update() override;
        void render(sf::RenderWindow & window) const override;
};

#endif
