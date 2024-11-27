#include "Player.h"
#include <iostream>
#include "BitmapHandler.h"
/// Konstruktor klasy Player.
/// 
/// Inicjalizuje gracza z przypisanymi klawiszami do poruszania sie oraz poczatkowymi wspolrzednymi (0, 0).
/// <param name="up">Klawisz ruchu w gore.</param>
/// <param name="down">Klawisz ruchu w dol.</param>
/// <param name="left">Klawisz ruchu w lewo.</param>
/// <param name="right">Klawisz ruchu w prawo.</param>
Player::Player(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right)
    : upKey(up), downKey(down), leftKey(left), rightKey(right), coords(Vector2f(0, 0)) {

}
/// Przesuwa gracza o wektor translacji.
/// 
/// <param name="translationVector">Wektor przesuniecia.</param>
void Player::translate(Vector2f translationVector) {
	
}
/// Obraca gracza o podany kat wzgledem punktu.
/// 
/// <param name="angle">Kat obrotu w stopniach.</param>
/// <param name="center">Punkt centralny obrotu.</param>
void Player::rotate(float angle, const Vector2f& center) {

}
/// Skaluje gracza wzgledem danego punktu.
/// 
/// <param name="factor">Wspolczynnik skalowania.</param>
/// <param name="center">Punkt centralny skalowania.</param>
void Player::scale(float factor, const Vector2f& center) {

}
/// Animuje gracza w zaleznosci od jego kierunku ruchu.
/// 
/// £aduje odpowiednia grafike na podstawie aktualnego kierunku ruchu i stanu poruszania siê.
/// <param name="clock">Zegar uzywany do obliczania klatki animacji.</param>
void Player::animate(sf::Clock clock) {
	std::string path;

	std::vector<std::string> paths;

		switch (direction)
		{
		case 0:
			paths = { "grafiki/gora1.png", "grafiki/gora2.png", "grafiki/gora3.png" };
			break;
		case 1:
			paths = { "grafiki/prawo1.png", "grafiki/prawo2.png", "grafiki/prawo3.png" };
			break;
		case 2:
			paths = { "grafiki/dol1.png", "grafiki/dol2.png", "grafiki/dol3.png" };
			break;
		case 3:
		default:
			paths = { "grafiki/lewo1.png", "grafiki/lewo2.png", "grafiki/lewo3.png" };
			break;
		}

	int idx;

	if (isMoving) {
		idx = (int)std::round(clock.getElapsedTime().asSeconds() * 10) % 2 + 1;
	}
	else {
		idx = 0;
	}

	BitmapHandler::loadFromFile(paths.at(idx));
}
/// Rysuje gracza na oknie.
/// 
/// Wywoluje funkcje odpowiedzialna za poruszanie sie oraz wyswietla odpowiednia grafike gracza.
/// <param name="window">Okno, w ktorym gracz jest rysowany.</param>
void Player::draw(RenderWindow& window) {
	move();
	BitmapHandler::display(window, coords);
}
/// Aktualizuje stan gracza.
/// 
/// Domyslnie laduje poczatkowa grafike gracza.
void Player::update() {
	std::string path = "grafiki/dol1.png";
	BitmapHandler::loadFromFile(path);
}
/// Ustawia kierunek ruchu w dol.
/// 
void Player::moveDown() {
	direction = 2;
	isMoving = true;
}
///Ustawia kierunek ruchu w lewo.
void Player::moveLeft() {
	direction = 3;
	isMoving = true;
}
///Ustawia kierunek ruchu w prawo.
void Player::moveRight() {
	direction = 1;
	isMoving = true;
}
///Ustawia kierunek ruchu w gory.
void Player::moveUp() {
	direction = 0;
	isMoving = true;
}
///Zatrzymuje ruch gracza.
void Player::stop() {
	isMoving = false;
}
/// Porusza gracza w aktualnym kierunku.
/// 
/// Jesli gracz osi¹gnie granice ekranu, jego wspó³rzêdne s¹ resetowane, aby "pojawil sie" po drugiej stronie.
void Player::move() {
	if (isMoving) {
		switch (direction) {
		case 0:
			coords.y -= 10;
			if (coords.y < 0) {
				coords.y = 600;
			}
			break;
		case 1:
			coords.x += 10;
			if (coords.x > 800) {
				coords.x = 0;
			}
			break;
		case 2:
			coords.y += 10;
			if (coords.y > 600) {
				coords.y = 0;
			}
			break;
		case 3:
			coords.x -= 10;
			if (coords.x < 0) {
				coords.x = 800;
			}
			break;
		}
	}


}