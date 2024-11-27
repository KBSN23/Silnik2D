#pragma once
#include <SFML/Graphics.hpp>
/// Klasa bazowa dla obiektow, ktore moga byc rysowane.
/// 
/// Klasa `DrawableObject` definiuje interfejs dla wszystkich obiektow, ktore maja
/// mozliwosc rysowania w oknie SFML.Jest to klasa abstrakcyjna, zawierajaca
/// jedna metode czysto wirtualna `draw`.
class DrawableObject
{
public:
	///  Konstruktor domyslny klasy DrawableObject.
	/// 
	/// Konstruktor inicjalizuje obiekt, ktory moze byc rysowany.
	///	Moze byc rozszerzany w klasach pochodnych.
	DrawableObject();
	/// Wirtualna metoda odpowiedzialna za rysowanie obiektu.
	/// 
	/// Metoda musi byc zaimplementowana w klasach pochodnych.
	/// <param name="window">Okno w ktorym obiekt bedzie rysowany.</param>
	virtual void draw(sf::RenderWindow& window) = 0;
};

