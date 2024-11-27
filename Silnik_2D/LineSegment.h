#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"


using namespace std;
using namespace sf;

class Point2D;
/// Klasa reprezentujaca odcinek linii w przestrzeni 2D, dziedziczaca po klasie ShapeObject.
/// 
/// Klasa ta umozliwia rysowanie, transformacje (przesuniecie, rotacje, skalowanie) i przechowywanie odcinka linii.
/// Zawiera metody do rysowania linii, ustawiania wspolrzednych oraz manipulowania obiektem.
class LineSegment : public ShapeObject
{
private:
	/// Tablica przechowujaca dwa punkty, które definiuja odcinek linii.
	Point2D edges[2];
	/// Kolor linii.
	Color color;
	/// Flaga okreslajaca, czy linia rosnie
	bool isRising;

public:
	/// Rysuje linie na ekranie.
	/// 
	/// Inicjalizuje obiekt odcinka linii, ustawiajac wspolrzedne dwoch punktow, kolor oraz flage rosnacej linii.
	/// <param name="a">Pierwszy punkt.</param>
	/// <param name="b">Drugi punkt.</param>
	/// <param name="color">Kolor odcinka lini.</param>
	/// <param name="isRising">Flaga okreslajaca, czy linia rosnie.</param>
	LineSegment(Vector2f a, Vector2f b, Color color, bool isRising);
	/// Rysuje linie na ekranie.
	/// 
	/// Rysuje linie miedzy dwoma punktami na przekazanym oknie renderowania.
	/// <param name="window">Okno renderowania.</param>
	/// <param name="a">Wspolrzedne pierwszego punktu.</param>
	/// <param name="b"><Wspolrzedne drugiego punktu./param>
	/// <param name="color_"></param>
	static void drawline(RenderWindow& window, Vector2f a, Vector2f b, Color color_);
	/// Rysuje linie za pomoca rownania linii.
	/// 
	/// Wykorzystuje rownanie matematyczne do narysowania linii pomiedzy dwoma punktami na oknie renderowania.
	/// <param name="window">Okno renderowania.</param>
	/// <param name="a">Wspolrzedne pierwszego punktu.</param>
	/// <param name="b">Wspolrzedne drugiego punktu.</param>
	/// <param name="color_">Kolor lini.</param>
	void drawlineEquation(RenderWindow& window, Vector2f a, Vector2f b, Color color_);
	/// Ustawia wspolrzedne punktow, ktore definiuja odcinek linii.
	/// 
	/// Metoda ustawia nowe wspolrzedne punktow, ktore definiuja odcinek linii.
	/// <param name="a">Nowy pierwszy punkt odcinka linii.</param>
	/// <param name="b">Nowy drugi punkt odcinka linii</param>
	void setCoords(Vector2f a, Vector2f b);
	/// Zwraca tablice punktow odcinka linii.
	/// 
	/// <returns>Tablica dwoch punktow (krawedzi) odcinka linii.</returns>
	Point2D* getEdges();
	/// Zwraca kolor odcinka linii.
	/// 
	/// <returns>Kolor linii.</returns>
	Color getColor();
	/// Przesuwa odcinek linii o zadany wektor translacji.
	/// 
	/// Metoda przesuwa odcinek linii o zadany wektor.
	/// <param name="translationVector">Wektor translacji, o ktory ma zostac przesuniety odcinek linii.</param>
	void translate(Vector2f translationVector) override;
	/// Rotuje odcinek linii wokol zadanego punktu o zadany kat.
	/// 
	/// Metoda rotuje odcinek linii wokol zadanego punktu o zadany kat (w stopniach).
	/// <param name="angle">Kat rotacji w stopniach.</param>
	/// <param name="center">Punkt centralny rotacji.</param>
	void rotate(float angle, const Vector2f& center) override;
	/// Skaluje odcinek linii wokol zadanego punktu.
	/// 
	/// Metoda skaluje odcinek linii o podany wspolczynnik skalowania, przy czym operacja odbywa sie wokol zadanego punktu.
	/// <param name="factor">Wspolczynnik skalowania.</param>
	/// <param name="center">Punkt, wokol ktorego ma odbywac sie skalowanie.</param>
	void scale(float factor, const Vector2f& center) override;
	/// Rysuje odcinek linii na oknie renderowania.
	/// 
	/// Rysuje odcinek linii na przekazanym oknie renderowania.
	/// <param name="window">Okno renderowania.</param>
	void draw(RenderWindow& window) override;
	/// Aktualizuje stan odcinka linii.
	/// 
	/// Metoda ta moze byc uzywana do aktualizacji stanu obiektu, np. w ramach logiki gry.
	void update() override;
};