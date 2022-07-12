#pragma once
class HomeScreen : public sf::Drawable
{
public:
	HomeScreen(sf::RenderWindow* window, const std::string* texName) {
		size = window->getSize();
		this->texName = *texName;
		coords();
	}
	~HomeScreen() {}
	void coords() {
		texture.loadFromFile(texName);
		sf::Vector2u tex_size = texture.getSize();
		vertex.setPrimitiveType(sf::Quads);
		vertex.resize(4);
		vertex[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
		vertex[1] = sf::Vertex(sf::Vector2f(size.x, 0), sf::Vector2f(tex_size.x, 0));
		vertex[2] = sf::Vertex(sf::Vector2f(size.x, size.y), sf::Vector2f(tex_size.x, tex_size.y));
		vertex[3] = sf::Vertex(sf::Vector2f(0, size.y), sf::Vector2f(0, tex_size.y));
	};
	void set_size(const sf::Vector2u* size) {
		this->size = *size;
	}
	sf::Vector2u* get_size() {
		return &size;
	}
	void set_texName(const std::string* texName) {
		this->texName = *texName;
	}
	std::string* get_texName() {
		return &texName;
	}
private:
	sf::RenderWindow* window;
	sf::Vector2u size;
	sf::Texture texture;
	std::string texName;
	sf::VertexArray vertex;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		states.texture = &texture;
		target.draw(vertex, states);
	}
};