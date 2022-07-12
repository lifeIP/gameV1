#include "lib.h"
#include "obj.h"
struct fr
{
	bool b0 : 1;
	bool b1 : 1;
	bool b2 : 1;
	bool b3 : 1;
	bool b4 : 1;
	bool b5 : 1;
	bool b6 : 1;
	bool b7 : 1;

	bool b8 : 1;
	bool b9 : 1;
	bool b10 : 1;
	bool b11 : 1;
	bool b12 : 1;
	bool b13 : 1;
	bool b14 : 1;
	bool b15 : 1;

	bool b16 : 1;
	bool b17 : 1;
	bool b18 : 1;
	bool b19 : 1;
	bool b20 : 1;
	bool b21 : 1;
	bool b22 : 1;
	bool b23 : 1;

	bool b24 : 1;
	bool b25 : 1;
	bool b26 : 1;
	bool b27 : 1;
	bool b28 : 1;
	bool b29 : 1;
	bool b30 : 1;
	bool b31 : 1;
};
union flg
{
	fr f;
	unsigned int ui;
};

void menu(
	Button* b0, Button* b1, Button* b2, Button* b3, Button* b4, Button* b5, Button* b6, Button* b7,
	HomeScreen* hs, SmallWindows* sw0, SmallWindows* sw1, SmallWindows* sw2, SmallWindows* sw3, SmallWindows* sw4,
	SmallWindows* sw5, SmallWindows* sw6, SmallWindows* sw7
	) 
{
	sf::VideoMode pz = sf::VideoMode::getFullscreenModes()[0];
	int p20x = 400;
	//button #0+
	b0->set_button_pos(&sf::Vector2f(40, 40));
	b0->set_button_size(&sf::Vector2u(p20x, 65));
	//button #0-
	//button #1+
	b1->set_button_pos(&sf::Vector2f(40, 115));
	b1->set_button_size(&sf::Vector2u(p20x, 65));
	//button #1-
	//button #2+
	b2->set_button_pos(&sf::Vector2f(40, 190));
	b2->set_button_size(&sf::Vector2u(p20x, 65));
	//button #2-
	//button #3+
	b3->set_button_pos(&sf::Vector2f(40, 265));
	b3->set_button_size(&sf::Vector2u(p20x, 65));
	//button #3-
	//button #4+
	b4->set_button_pos(&sf::Vector2f(pz.width - 300, pz.height - 65));
	b4->set_button_size(&sf::Vector2u(300, 65));
	b4->set_color(0, 0, 0, 0);
	b4->set_text(std::string("Сообщество"));
	b4->set_font_size(8);
	b4->set_offset_text(sf::Vector2u(20,20));
	//button #4-
}

int main() {
	flg p;
	p.ui = 0;
	bool button[8];
	for (int i = 0; i < 8; i++) {
		button[i] = false;
	}
	sf::Uint32 style = sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "", style);
	//warehouse of objects+
	std::string texName = "wall.jpg";
	HomeScreen home_screen(&window, &texName);
	SmallWindows sw0;
	SmallWindows sw1;
	SmallWindows sw2;
	SmallWindows sw3;
	Button button_0(&window, button, 0);
	Button button_1(&window, button, 1);
	Button button_2(&window, button, 2);
	Button button_3(&window, button, 3);
	Button button_4(&window, button, 4);
	Button button_5(&window, button, 5);
	Button button_6(&window, button, 6);
	Button button_7(&window, button, 7);
	menu(&button_0, &button_1, &button_2, &button_3, &button_4, &button_5, &button_6, &button_7,
		&home_screen, &sw0, &sw1, &sw2, &sw3, &sw0, &sw1, &sw2, &sw3
	);
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
					if (button[0]) {
						std::cout << '0' << std::endl;
					}
					if (button[1]) {
						std::cout << '1' << std::endl;
					}
					if (button[2]) {
						std::cout << '2' << std::endl;
					}
					if (button[3]) {
						std::cout << '3' << std::endl;
					}
					if (button[4]) {
						std::cout << '4' << std::endl;
					}
					if (button[5]) {
						std::cout << '5' << std::endl;
					}
					if (button[6]) {
						std::cout << '6' << std::endl;
					}
					if (button[7]) {
						std::cout << '7' << std::endl;
					}
					break;
				case sf::Mouse::Right:

					break;
				}
			}
		}
		window.clear(sf::Color::Black);
		//Place for the rendering function+
		window.draw(home_screen);
		button_0.button_monitoring();
		window.draw(button_0);
		button_1.button_monitoring();
		window.draw(button_1);
		button_2.button_monitoring();
		window.draw(button_2);
		button_3.button_monitoring();
		window.draw(button_3);
		button_4.button_monitoring();
		window.draw(button_4);

		//Place for the rendering function-
		window.display();
	}
	return 0;
}
