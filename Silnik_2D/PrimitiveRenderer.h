#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
using namespace sf;

/// Funktor hashujacy dla obiektow `Vector2f`.
/// 
///  Funkcja hashujaca umozliwia uzycie `Vector2f` jako klucza w strukturach takich jak `unordered_map`.
struct VectorHash {
	size_t operator()(const Vector2f& v) const {
		return hash<float>()(v.x) ^ hash<float>()(v.y);
	}
};
/// Klasa do renderowania prymitywow graficznych.
/// 
/// Klasa `PrimitiveRenderer` oferuje metody do rysowania pikseli, linii, wielokatow, okrêgow i elips,
///	a takze metody do wypelniania obszarow za pomoca algorytmow takich jak `fill`.
class PrimitiveRenderer
{
public:
	/// Mapa przechowujaca kolory poszczegolnych pikseli.
	/// 
	/// Klucz: wspolrzedne pikseli `Vector2f`.
	///	Wartosc : kolor piksela`Color`.
	static unordered_map<Vector2f, Color, VectorHash> pixelColors;
	///	Rysuje pojedynczy piksel w zadanym miejscu i kolorze.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="coords">Wspolrzedne piksela.</param>
	/// <param name="color">Kolor piksela.</param>
	static void drawPixel(RenderWindow& window, Vector2f coords, Color color);
	/// Rysuje okrag.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="center">Srodek okregu.</param>
	/// <param name="radius">Promien okregu.</param>
	/// <param name="color">Kolor okregu.</param>
	void drawCircle(RenderWindow& window, Vector2f center, int radius, Color color);
	/// Rysuje elipse.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="center">Srodek elipsy.</param>
	/// <param name="a">Polos pozioma elipsy.</param>
	/// <param name="b">Polos pionowa elipsy.</param>
	/// <param name="color">Kolor elipsy.</param>
	void drawEllipse(RenderWindow& window, Vector2f center, int a, int b, Color color);
	///  Rysuje linie lamana utworzona z odcinkow.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="s">Wektor odcinkow tworzacych lamana.</param>
	void drawPolyline(RenderWindow& window, vector<LineSegment> s);
	/// Rysuje linie lamana utworzona z punktow.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="points">Wektor punktow tworzacy lamana.</param>
	/// <param name="closed">Czy linia lamana ma byc zamknieta.</param>
	void drawPolyline(RenderWindow& window, vector<Point2D> points, bool closed);
	/// Rysuje wielokat zdefiniowany przez punkty.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="points">Wektor punktow definujacy wielakat.</param>
	void drawPolygon(RenderWindow& window, vector<Point2D> points);
	/// Rysuje wielokat zdefiniowany przez odcinki.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="segments">Wektor odcinkow definiujacych wielokat.</param>
	void drawPolygon(RenderWindow& window, vector<LineSegment> segments);
	/// Wypelnia obszar od zadanej pozycji za pomoca koloru wypelnienia.
	/// 
	/// <param name="window">Okno renderowania.</param>
	/// <param name="start">Punkt poczatkowy wypelniania.</param>
	/// <param name="fillColor">Kolor wypelniania.</param>
	/// <param name="borderColor">Kolor granicy, na ktorej wypelnianie ma sie zatrzymac.</param>
	void fill(RenderWindow& window, Vector2f start, Color fillColor, Color borderColor);
	/// Konstruktor inicjalizujacy kolor.
	/// 
	/// <param name="color_">Kolor inicjalizujacy obiekt.</param>
	PrimitiveRenderer(Color color_);
	/// Destruktor klasy PrimitiveRenderer.
	~PrimitiveRenderer();
	///	Konstruktor domyslny klasy PrimitiveRenderer.
	PrimitiveRenderer();
protected:
	///	Domyslny kolor obiektow rysowanych przez renderer.
	Color color;
	
};

