#include "Point2D.h"
#include "PrimitiveRenderer.h"
/// Klasa reprezentujaca punkt w przestrzeni 2D.
/// 
/// Klasa dziedziczy po ShapeObject i oferuje funkcjonalnosci zwiazane z rysowaniem,
/// transformacjami geometrycznymi(translacja, rotacja, skalowanie) oraz zarzadzaniem
/// pozycja i kolorem punktu.
Point2D::Point2D() : ShapeObject()
{

};
///  Konstruktor parametryczny.
/// 
///  Tworzy punkt w zadanych wspolrzednych i z okreslonym kolorem.
/// <param name="coords">Wspolrzedne punktu w przestrzeni 2D.</param>
/// <param name="color">Kolor punktu.</param>
Point2D::Point2D(Vector2f coords, Color color){
	this->coords = coords;
	this->color = color;
}
/// Rysuje punkt w oknie graficznym.
/// 
/// Wykorzystuje klase PrimitiveRenderer do narysowania piksela w zadanych wspolrzednych 
///	i o okreslonym kolorze.
/// <param name="window">Okno renderowania.</param>
void Point2D::draw(RenderWindow& window) {
	 PrimitiveRenderer::drawPixel(window, coords, color);
}
/// Ustawia nowe wspolrzedne punktu.
/// 
/// <param name="newCoords">Nowe wspolrzedne punktu w przestrzeni 2D.</param>
void Point2D::setCoords(Vector2f newCoords) {
	this->coords = newCoords;
}
/// Pobiera aktualne wspolrzedne punktu.
/// 
/// <returns>Wspolrzedne punktu jako obiekt Vector2f.</returns>
Vector2f Point2D::getCoords()
{
	return coords;
}
/// Pobiera aktualny kolor punktu.
/// 
/// <returns>Kolor punktu jako obiekt Color.</returns>
Color Point2D::getColor()
{
	return color;
}
/// Przesuwa punkt o zadany wektor translacji.
/// 
/// Dodaje do wspolrzednych punktu wektor translacji.
/// <param name="translationVector">Wektor, o ktory punkt ma zostac przesuniety.</param>
void Point2D::translate(Vector2f translationVector) {
	this->coords += translationVector;
}
/// Obraca punkt wokol zadanego centrum o okreslony kat.
/// 
/// Oblicza nowe wspolrzedne punktu na podstawie obrotu o zadany kat w stopniach 
///	wzgledem zadanego centrum.
/// <param name="angle">Kat obrotu w stopniach.</param>
/// <param name="center">Punkt, wzgledem ktorego wykonywany jest obrot.</param>
void Point2D::rotate(float angle, const Vector2f& center) {
	Vector2f translatedCoords = coords - center;

	float rad = angle * 3.14159265f / 180.0f;
	float cosAngle = cos(rad);
	float sinAngle = sin(rad);

	float rotatedX = translatedCoords.x * cosAngle - translatedCoords.y * sinAngle;
	float rotatedY = translatedCoords.x * sinAngle + translatedCoords.y * cosAngle;

	coords = Vector2f(rotatedX, rotatedY) + center;
}
/// Skaluje punkt wzgledem zadanego centrum.
/// 
/// Oblicza nowe wspolrzedne punktu na podstawie skalowania o zadany wspolczynnik 
///	wzgledem okreslonego centrum.
/// <param name="factor">Wspolczynnik skalowania.</param>
/// <param name="center">Punkt, wzgledem ktorego wykonywane jest skalowanie.</param>
void Point2D::scale(float factor, const Vector2f& center) {
		Vector2f translatedCoords = coords - center;

		float scaledX = translatedCoords.x * factor;
		float scaledY = translatedCoords.y * factor;

		coords = Vector2f(scaledX, scaledY) + center;
}
/// Aktualizuje stan obiektu.
/// 
/// Obecnie ta metoda jest pusta, ale moze byc nadpisana w klasach pochodnych, 
///	jesli punkt wymaga specyficznej logiki aktualizacji w trakcie dzialania aplikacji.
void Point2D::update() {

}