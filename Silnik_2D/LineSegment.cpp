#include "LineSegment.h"
#include "PrimitiveRenderer.h"
/// Konstruktor klasy LineSegment
/// 
/// Tworzy obiekt odcinka linii na podstawie dwoch punktow, koloru oraz flagi wskazujacej, czy linia rosnie.
/// <param name="a">Pierwszy punkt odcinka linii.</param>
/// <param name="b">Drugi punkt odcinka linii.</param>
/// <param name="color">Kolor odcinka linii.</param>
/// <param name="isRising">Flaga wskazujaca, czy linia rosnie.</param>
LineSegment::LineSegment(Vector2f a, Vector2f b, Color color, bool isRising)
    : color(color), isRising(isRising)
{
    edges[0] = Point2D(a, color);
    edges[1] = Point2D(b, color);
}
/// Rysuje odcinek linii na oknie renderowania.
/// 
/// Metoda rysuje linie w zaleznosci od wartosci flagi `isRising`.
/// Jesli `isRising` jest prawdziwe, uzywa algorytmu rysowania linii; w przeciwnym wypadku uzywa rownania linii.
/// <param name="window">Okno renderowania.</param>
void LineSegment::draw(RenderWindow& window)
{
	if (isRising)
		drawline(window, edges[0].getCoords(), edges[1].getCoords(), color);
	else
		drawlineEquation(window, edges[0].getCoords(), edges[1].getCoords(), color);
}
/// Rysuje linie za pomoca algorytmu Bresenhama.
/// 
/// Uzywa algorytmu Bresenhama do rysowania pikseli linii pomiedzy dwoma punktami.
/// <param name="window">Okno renderowania.</param>
/// <param name="a">Pierwszy punkt odcinka linii.</param>
/// <param name="b">Drugi punkt odcinka linii.</param>
/// <param name="color_">Kolor odcinka linii.</param>
void LineSegment::drawline(RenderWindow& window, Vector2f a, Vector2f b, Color color_)
{
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int sx = (a.x < b.x) ? 1 : -1;
    int sy = (a.y < b.y) ? 1 : -1;
    int err = dx - dy;


    while (true)
    {
        PrimitiveRenderer::drawPixel(window, a, color_);

        if (a.x == b.x && a.y == b.y)
        {
            break;
        }
        int e2 = err * 2;

        if (e2 > -dy)
        {
            err -= dy;
            a.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            a.y += sy;
        }

    }
}
/// Rysuje linie za pomoca rownania linii.
/// 
/// Wykorzystuje rownanie liniowe do obliczenia i rysowania pikseli linii pomiedzy dwoma punktami.
/// <param name="window">Okno renderowania.</param>
/// <param name="a">Pierwszy punkt odcinka linii.</param>
/// <param name="b">Drugi punkt odcinka linii.</param>
/// <param name="color_">Kolor odcinka linii.</param>
void LineSegment::drawlineEquation(RenderWindow& window, Vector2f a, Vector2f b, Color color_)
{
    if (a.x == b.x)
    {
        float yMin = min(a.y, b.y);
        float yMax = max(a.y, b.y);

        for (float y = yMin; y <= yMax; y++)
        {
            PrimitiveRenderer::drawPixel(window, Vector2f(a.x, y), color_);
        }
        return;
    }

    float m = (b.y - a.y) / (b.x - a.x);
    float c = a.y - m * a.x;

    if (abs(b.x - a.x) > abs(b.y - a.y))
    {
        float xMin = min(a.x, b.x);
        float xMax = max(a.x, b.x);

        for (float x = xMin; x <= xMax; x++)
        {
            float y = m * x + c;
            PrimitiveRenderer::drawPixel(window, Vector2f(x, y), color_);
        }
    }
    else
    {
        float yMin = min(a.y, b.y);
        float yMax = max(a.y, b.y);

        for (float y = yMin; y <= yMax; y++)
        {
            float x = (y - c) / m;
            PrimitiveRenderer::drawPixel(window, Vector2f(x, y), color_);
        }
    }
}
/// Ustawia nowe wspolrzedne punktow odcinka linii.
/// 
/// <param name="a">Nowy pierwszy punkt odcinka linii.</param>
/// <param name="b">Nowy drugi punkt odcinka linii.</param>
void LineSegment::setCoords(Vector2f a, Vector2f b)
{
	edges[0].setCoords(a);
	edges[1].setCoords(b);

}
/// Zwraca tablice dwoch punktow, ktore definiuja odcinek linii.
///     
/// <returns> Tablica punktow reprezentujacych konce odcinka linii.</returns>
Point2D* LineSegment::getEdges()
{
	return edges;
}
/// Zwraca kolor odcinka linii.
/// 
/// <returns>Kolor linii.</returns>
Color LineSegment::getColor()
{
	return color;
}
/// Przesuwa odcinek linii o zadany wektor translacji.
/// 
/// <param name="translationVector">Wektor translacji.</param>
void LineSegment::translate(Vector2f translationVector) {
    edges[0].translate(translationVector);
    edges[1].translate(translationVector);
}
/// Obraca odcinek linii wokol zadanego punktu o okreslony kat.
/// 
/// <param name="angle">Kat rotacji w stopniach.</param>
/// <param name="center">Punkt centralny rotacji.</param>
void LineSegment::rotate(float angle, const Vector2f& center) {
    edges[0].rotate(angle, center);
    edges[1].rotate(angle, center);
}
/// Skaluje odcinek linii o okreslony wspolczynnik wzgledem zadanego punktu.
/// 
/// <param name="factor">Wspolczynnik skalowania.</param>
/// <param name="center">Punkt centralny skalowania.</param>
void LineSegment::scale(float factor, const Vector2f& center) {
    edges[0].scale(factor, center);
    edges[1].scale(factor, center);
}
/// Aktualizuje stan odcinka linii.
/// 
/// Metoda do aktualizacji stanu obiektu. Aktualnie pusta, moze byc rozszerzona w przyszlosci.
void LineSegment::update() {

}