#pragma once
#include "ShapeObject.h"
#include "SpriteObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;
/// Klasa reprezentujaca gracza w grze.
/// 
/// Klasa `Player` dziedziczy wirtualnie z `ShapeObject` i `SpriteObject`.
///	Oferuje funkcjonalnosci zwiazane z poruszaniem sie, animacja oraz rysowaniem obiektu gracza.
class Player : public virtual ShapeObject , public virtual SpriteObject
{

public:
	/// Klawisze sterujace ruchem gracza.
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
	///Wspolrzedne gracza w przestrzeni 2D.
	Vector2f coords;
	/// Kierunek poruszania sie gracza.
	/// 
	///	Wartosc 1 oznacza domyslny kierunek ruchu.
	int direction = 1;
	/// Flaga okreslajaca, czy gracz jest w ruchu.
	bool isMoving = false;
	/// Konstruktor klasy Player.
	/// 
	///	Inicjalizuje obiekt gracza i przypisuje klawisze sterujace.
	/// <param name="up">Klawisz odpowiadajacy za ruch w gore.</param>
	/// <param name="down">Klawisz odpowiadajacy za ruch w dol.</param>
	/// <param name="left">Klawisz odpowiadajacy za ruch w lewo.</param>
	/// <param name="right">Klawisz odpowiadajacy za ruch w prawo.</param>
	Player(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right);
	/// Przemieszcza gracza o zadany wektor.
	/// 
	/// <param name="translationVector">Wektor translacji.</param>
	void translate(Vector2f translationVector) override;
	/// Obraca gracza o zadany kat wokol danego srodka.
	/// 
	/// <param name="angle">Kat obrotu w stopniach.</param>
	/// <param name="center"> Punkt, wokol ktorego nastepuje obrot.</param>
	void rotate(float angle, const Vector2f& center) override;
	/// Skalowanie gracza o zadany wspolczynnik wzgledem podanego srodka.
	/// 
	/// <param name="factor">Wspolczynnik skalowania.</param>
	/// <param name="center">Punkt odniesienia do skalowania.</param>
	void scale(float factor, const Vector2f& center) override;
	/// Rysuje obiekt gracza w oknie gry.
	/// 
	/// <param name="window">Okno w ktorym obiekt zostanie narysowany.</param>
	void draw(RenderWindow& window) override;
	/// Aktualizuje stan gracza.
	/// 
	/// Metoda zawiera logike dotyczaca ruchu i innych interakcji gracza.
	void update() override;
	/// Animuje obiekt gracza.
	/// 
	/// <param name="clock">Clock wykorzystywany do kontrolowania czasu animacji.</param>
	void animate(sf::Clock clock) override;
	///Funkcja odpowiedzialna za ruch gracza w lewo.
	void moveLeft();
	///Funkcja odpowiedzialna za ruch gracza w prawo.
	void moveRight();
	///Funkcja odpowiedzialna za ruch gracza w gore.
	void moveUp();
	///Funkcja odpowiedzialna za ruch gracza w dol.
	void moveDown();
	///Funkcja odpowiedzialna za zatrzymanie gracza.
	void stop();
	///Wywoluje odpowiednia metode ruchu w zaleznosci od biezacego kierunku.
	void move();
};

