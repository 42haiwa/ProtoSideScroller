#include <SFML/Graphics.hpp>
#include "Player.h"
#include "DirtBlock.h"
#include "constants.h"

int main(void) {
	sf::RenderWindow window{sf::VideoMode{W_WIDTH, W_HEIGHT}, "window"};
	auto player = Player{"assets/player/Player.png"};
	auto dirtBlock = DirtBlock{sf::Vector2f{0, 100}};

	while (window.isOpen()) {
		sf::Event event{};

		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
					break;

				default:
					break;
			}
		}

		window.clear();

		dirtBlock.update();
		dirtBlock.render(window);

		player.update(window);
		player.render(window);

		window.display();
	}

	return 0;
}