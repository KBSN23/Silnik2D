#pragma once
#include <SFML/Graphics.hpp>
/// Klasa obslugujaca tworzenie, ladowanie i wyswietlanie bitmap w SFML.
/// 
/// Klasa BitmapHandler zapewnia statyczne metody do operacji na bitmapach, takich jak:
/// - Tworzenie nowych bitmap o zadanych wymiarach i kolorze.
/// -Wczytywanie bitmap z plikow.
/// -Czyszczenie bitmapy wybranym kolorem.
/// -Wyswietlanie bitmapy w oknie SFML.
class BitmapHandler
{
private:
	///Tekstura przechowuj¹ca dane bitmapy.
	static sf::Texture texture;
	///Sprite sluzacy do rysowania bitmapy na ekranie.
	static sf::Sprite sprite;
	///Obraz przechowujacy piksele bitmapy.
	static sf::Image image;

public:
	/// Konstruktor domyslny klasy BitmapHandler.
	/// 
	/// Konstruktor nie wykonuje zadnych operacji, poniewaz wszystkie metody
	///	i dane s¹ statyczne.
	BitmapHandler() {};
	/// Tworzy nowa bitmape o zadanej szerokosci, wysokosci i kolorze.
	/// 
	/// <param name="width">Szerokosc bitmapy.</param>
	/// <param name="height">Wysokosc bitmapy.</param>
	/// <param name="color">Kolor wypelnienia bitmapy.</param>
	static void create(unsigned int width, unsigned int height, const sf::Color& color = sf::Color::White);
	/// Wczytuje bitmape z pliku.
	/// 
	/// <param name="filename">Sciezka do pliku zawierajacego obraz.</param>
	static void loadFromFile(std::string& filename);
	/// Czysci bitmape, wypelniajac ja wybranym kolorem.
	/// 
	/// <param name="color">Kolor uzyty do wypelnienia bitmapy.</param>
	static void clear(const sf::Color& color = sf::Color::Transparent);
	///  Wyswietla bitmape w zadanym oknie SFML.
	/// 
	/// <param name="window">Okno w ktorym zostanie wyswietlony obraz.</param>
	/// <param name="pos">Pozycja w oknie, gdzie bitmapa zostanie narysowana.</param>
	static void display(sf::RenderWindow& window, sf::Vector2f pos);
};

