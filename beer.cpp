/*!
*	\author Olha Sereda
*   \author Karina Demiankova
*	\date 2022
*   \copyright Olha Sereda (olha.sereda@student.uj.edu.pl)
*   \copyright Karina Demiankova (karina.demiankova@student.uj.edu.pl)
*/
#include "beer.hpp"

Beer::Beer(sf::Vector2f coord)
{
	this->coord = coord;
	this->TimeOfLife = 100;
	//load image from file
	image.loadFromFile("beer-icon.png");
	//load picture in texture
	texture.loadFromImage(image);
	//load texture in sprite
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
	sprite.setPosition(this->coord);
}

void Beer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// draw a beer 
	
	target.draw(sprite, states);
}

sf::Vector2f Beer::get_coord(void) {
	return this->coord;
}

sf::FloatRect Beer::get_rect(void)
{
	return sf::FloatRect(this->coord.x, this->coord.y, sprite.getTextureRect().width, sprite.getTextureRect().height);
}


void Beer::update(void)
{
	--TimeOfLife;
}

bool Beer::IsAlive(void)
{
	if (TimeOfLife > 0) return true; else return false;
}

