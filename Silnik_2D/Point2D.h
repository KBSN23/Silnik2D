#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeObject.h"

using namespace sf;
using namespace std;
/// Klasa reprezentujaca punkt dwuwymiarowy w przestrzeni.
/// 
/// Dziedziczy po klasie ShapeObject i dodaje funkcjonalnosci zwiazane z rysowaniem,
///	translacja, rotacja i skalowaniem punktu.
class Point2D : public virtual ShapeObject
{
private:
	///Wspolrzedne punktu.
	Vector2f coords;
	///Kolor punktu.
	Color color;
public:
	/// Konstruktor domyslny klasy Point2D.
	Point2D();
	/// Konstruktor klasy Point2D.
	/// 
	///	Inicjalizuje punkt z podanymi wspolrzednymi i kolorem.
	/// <param name="coords">Wspolrzedne punktu.</param>
	/// <param name="color">Kolor punktu.</param>
	Point2D(Vector2f coords, Color color);
	/// Rysuje punkt w podanym oknie.
	/// 
	/// <param name="window">Referencja do okna, w ktorym punkt ma zostac narysowany.</param>
	void draw(RenderWindow& window) override;
	/// Ustawia nowe wspolrzedne punktu.
	/// 
	/// <param name="newCoords">Nowe wspolrzedne punktu.</param>
	void setCoords(Vector2f newCoords);
	/// Zwraca aktualne wspolrzedne punktu.
	/// 
	/// <returns>Wspolrzedne punktu jako obiekt Vector2f.</returns>
	Vector2f getCoords();
	/// Zwraca kolor punktu.
	/// 
	/// <returns>Kolor punktu jako obiekt Color.</returns>
	Color getColor();
	///	Przesuwa punkt o podany wektor translacji.
	/// 
	/// <param name="translationVector">Wektor, o ktory punkt zostanie przesuniety.</param>
	void translate(Vector2f translationVector) override;
	///	Obraca punkt wokol podanego punktu centralnego.
	/// 
	/// <param name="angle">Kat obrotu w stopniach.</param>
	/// <param name="center">Punkt centralny obrotu.</param>
	void rotate(float angle, const Vector2f& center) override;
	/// Skaluje punkt wzgledem podanego punktu centralnego.
	/// 
	/// <param name="factor">Wspolczynnik skalowania.</param>
	/// <param name="center">Punkt centralny skalowania.</param>
	void scale(float factor, const Vector2f& center) override;
	/// Aktualizuje stan punktu.
	/// 
	/// Funkcja w tej wersji jest pusta, ale moze byc rozszerzona w przyszlosci.
	void update() override;
};

