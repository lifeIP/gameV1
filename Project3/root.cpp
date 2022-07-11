#include "lib.h"
#include "obj.h"
int main() {
	sf::Uint32 style = sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "", style);
	//warehouse of objects+

	//warehouse of objects-
	while (window.isOpen()) {
		sf::Event some_event;
		while (window.pollEvent(some_event)) {
			if (some_event.type == sf::Event::EventType::KeyPressed) {
				switch (some_event.key.code)
				{
				case sf::Keyboard::E:
					//inventory
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
			}
			else if (some_event.type == sf::Event::EventType::MouseButtonReleased) {
				switch (some_event.mouseButton.button)
				{
				case sf::Mouse::Left:
					break;
				}
			}
		}
		window.clear(sf::Color::Black);
		//Place for the rendering function+
		
		//Place for the rendering function-
		window.display();
	}
	return 0;
}
