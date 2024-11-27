#include "PrimitiveRenderer.h"
#include <unordered_map>
using namespace sf;
using namespace std;
/// <summary>
/// Konstruktor
/// </summary>
/// <param name="color_">Kolor jaki ma miec obiekt</param>
PrimitiveRenderer::PrimitiveRenderer(Color color_)
{
    this->color = color_;

}
///Destruktor 
PrimitiveRenderer::~PrimitiveRenderer()
{

}
///Konstruktor domyslny
PrimitiveRenderer::PrimitiveRenderer()
{

}
/// Statyczny czlonek klasy przechowujacy kolory pikseli do renderowania
unordered_map<Vector2f, Color, VectorHash> PrimitiveRenderer::pixelColors;
///  Rysuje linie ³amana na podstawie listy odcinków.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="segments">Wektor zawieraj¹cy odcinki do narysowania.</param>
void PrimitiveRenderer::drawPolyline(RenderWindow& window, vector<LineSegment> segments)
{
    for (size_t i = 0; i < segments.size(); ++i)
    {
        LineSegment::drawline(window, segments[i].getEdges()[0].getCoords(), segments[i].getEdges()[1].getCoords(), segments[i].getColor());
    }
}
/// Rysuje wielokat na podstawie listy punktow.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="points">Wektor punktow reprezentujacych wierzcholki wielokata.</param>
void PrimitiveRenderer::drawPolygon(RenderWindow& window, vector<Point2D> points) {
    if (points.size() < 3) return;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        LineSegment::drawline(window, points[i].getCoords(), points[i + 1].getCoords(), points[i].getColor());
    }

    LineSegment::drawline(window, points.back().getCoords(), points.front().getCoords(), points.front().getColor());
}
/// Rysuje wielokat na podstawie listy odcinkow.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="segments">Wektor zawjerajacy odcinki reprezentujace boki wielokata</param>
void PrimitiveRenderer::drawPolygon(RenderWindow& window, vector<LineSegment> segments) {
    if (segments.size() < 2) return;

	Point2D firstEdge = segments.front().getEdges()[1];
	Point2D lastEdge = segments.at(segments.size() - 1).getEdges()[1];

    for (size_t i = 0; i < segments.size(); ++i) {
        Point2D* edges = segments[i].getEdges();
        LineSegment::drawline(window, edges[0].getCoords(), edges[1].getCoords(), segments[i].getColor());
    }

	LineSegment::drawline(window, firstEdge.getCoords(), lastEdge.getCoords(), lastEdge.getColor());
}
/// Rysuje linie ³amana na podstawie listy punktow, opcjonalnie zamykajac ja w wielokat.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="points">Wektor punktow reprezentujacych wierzcholki linii.</param>
/// <param name="closed">Flaga okreslajaca, czy linia lamana ma byc zamknieta w wielokat.</param>
void PrimitiveRenderer::drawPolyline(RenderWindow& window, vector<Point2D> points, bool closed)
{
    if (points.size() < 2) return;

    for (size_t i = 0; i < points.size() - 1; ++i)
    {
        LineSegment::drawline(window, points[i].getCoords(), points[i + 1].getCoords(), points[i].getColor());
    }

    if (closed)
    {
        LineSegment::drawline(window, points.back().getCoords(), points.front().getCoords(), points[0].getColor());
    }

}
/// Wypelnia obszar kolorem, rozpoczynajac od zadanego punktu.
/// 
/// <param name="window">Okno renderowania</param>
/// <param name="start">Punkt poczatkowy.</param>
/// <param name="fillColor">Kolor wypelnienia.</param>
/// <param name="borderColor">Kolor graniczny.</param>
void PrimitiveRenderer::fill(RenderWindow& window, Vector2f start, Color fillColor, Color borderColor) {
    if (start.x < 0 || start.x >= window.getSize().x || start.y < 0 || start.y >= window.getSize().y) {
        return;
    }

    if (pixelColors[start] == fillColor || pixelColors[start] == borderColor) {
        return;
    }

    stack<Vector2f> pixels;
    pixels.push(start);

    while (!pixels.empty()) {
        Vector2f current = pixels.top();
        pixels.pop();

        if (current.x < 0 || current.x >= window.getSize().x || current.y < 0 || current.y >= window.getSize().y) {
            continue;
        }

        if (pixelColors[current] == fillColor || pixelColors[current] == borderColor) {
            continue;
        }

        drawPixel(window, current, fillColor);

        pixels.push(Vector2f(current.x + 1, current.y));
        pixels.push(Vector2f(current.x - 1, current.y));
        pixels.push(Vector2f(current.x, current.y + 1));
        pixels.push(Vector2f(current.x, current.y - 1));
    }
}
/// Rysuje pojedynczy piksel na ekranie.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="coords">Wspolrzedne piksela</param>
/// <param name="color">Kolor piksela</param>
void PrimitiveRenderer::drawPixel(RenderWindow& window, Vector2f coords, Color color) {
    Vertex point(coords, color);
    window.draw(&point, 1, Points);
    pixelColors[coords] = color;
}
/// Rysuje elipse o zadanym srodku i wymiarach.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="center">Srodek elipsy.</param>
/// <param name="a">Polosie elipsy w poziomie.</param>
/// <param name="b">Polosie elipsy w pionie.</param>
/// <param name="color">Kolor elipsy.</param>
void PrimitiveRenderer::drawEllipse(RenderWindow& window, Vector2f center, int a, int b, Color color)
{
    int x = 0;
    int y = b;

    int a2 = a * a;
    int b2 = b * b;
    int fa2 = 4 * a2;
    int fb2 = 4 * b2;

    int sigma = 2 * b2 + a2 * (1 - 2 * b);

    while (b2 * x <= a2 * y)
    {
        drawPixel(window, Vector2f(center.x + x, center.y + y), color);
        drawPixel(window, Vector2f(center.x - x, center.y + y), color);
        drawPixel(window, Vector2f(center.x + x, center.y - y), color);
        drawPixel(window, Vector2f(center.x - x, center.y - y), color);

        if (sigma >= 0)
        {
            sigma += fa2 * (1 - y);
            y--;
        }
        sigma += b2 * ((4 * x) + 6);
        x++;
    }

    x = a;
    y = 0;
    sigma = 2 * a2 + b2 * (1 - 2 * a);

    while (a2 * y <= b2 * x)
    {
        drawPixel(window, Vector2f(center.x + x, center.y + y), color);
        drawPixel(window, Vector2f(center.x - x, center.y + y), color);
        drawPixel(window, Vector2f(center.x + x, center.y - y), color);
        drawPixel(window, Vector2f(center.x - x, center.y - y), color);

        if (sigma >= 0)
        {
            sigma += fb2 * (1 - x);
            x--;
        }
        sigma += a2 * ((4 * y) + 6);
        y++;
    }
}
/// Rysuje okrag o zadanym srodku i promieniu.
/// 
/// <param name="window">Okno renderowania.</param>
/// <param name="center">Srodek okregu.</param>
/// <param name="radius">Promien okregu.</param>
/// <param name="color">Kolor okregu.</param>
void PrimitiveRenderer::drawCircle(RenderWindow& window, Vector2f center, int radius, Color color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x)
    {
        drawPixel(window, Vector2f(center.x + x, center.y + y), color);
        drawPixel(window, Vector2f(center.x - x, center.y + y), color);
        drawPixel(window, Vector2f(center.x + x, center.y - y), color);
        drawPixel(window, Vector2f(center.x - x, center.y - y), color);
        drawPixel(window, Vector2f(center.x + y, center.y + x), color);
        drawPixel(window, Vector2f(center.x - y, center.y + x), color);
        drawPixel(window, Vector2f(center.x + y, center.y - x), color);
        drawPixel(window, Vector2f(center.x - y, center.y - x), color);

        if (d <= 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
