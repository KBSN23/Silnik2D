#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;
/// Klasa glownego silnika gry.
/// 
/// Zarzadza petla gry, renderowaniem, obsluga zdarzen oraz podstawowymi funkcjami inicjalizacji i zakonczenia programu.
class Engine
{
public:
	/// Konstruktor klasy Engine
	/// 
	/// <param name="window_width">Szerokosc okna gry w pikselach.</param>
	/// <param name="window_height">Wysokosc okna gry w pikselach.</param>
	/// <param name="clear_color">Kolor czyszczenia ekranu.</param>
	/// <param name="frame_limit">Ograniczenie liczby klatek na sekunde.</param>
	/// <param name="full_screen">Flaga okreslajaca, czy tryb pelnoekranowy jest aktywny.</param>
	Engine(unsigned int window_width, unsigned int window_height, sf::Color clear_color, unsigned int frame_limit, bool full_screen);
	/// Destruktor klasy Engine.
	/// 
	/// Zwalnia zasoby uzywane przez silnik gry.
	~Engine();
	/// Inicjalizuje biblioteke graficzna SFML.
	/// 
	/// Tworzy okno renderowania i ustawia parametry poczatkowe.
	/// <returns>true jesli inicjalizacja zakonczyla sie powodzeniem, false w przeciwnym wypadku.</returns>
	bool initialize();
	///  Uruchamia glowna petle gry.
	/// 
	/// Zarzadza cyklem zdarzen, aktualizacji i renderowania.
	void run();
	/// Obsluguje zdarzenia zwiazane z mysza i klawiatura.
	/// 
	/// <param name="player"> Obiekt gracza, ktorego zdarzenia moga dotyczyc.</param>
	void events(Player& player);
	/// Aktualizuje stan gry.
	/// 
	/// Funkcja przeznaczona do implementacji logiki gry w kolejnych iteracjach.
	void update();
	/// Renderuje scene gry.
	/// 
	/// Czysci ekran, rysuje obiekty i wyswietla je na ekranie.
	/// <param name="player">Obiekt gracza do rysowania.</param>
	/// <param name="clock">Zegar gry sluzacy do zarzadzania czasem.</param>
	void render(Player& player, sf::Clock clock);
	/// Zwalnia zasoby i zamyka program.
	void cleanup();
	/// Zapisuje bledy do pliku logu.
	/// 
	/// <param name="message">Widomosc bledu do zapisu w logu.</param>
	void logError(const string& message); 
	
private:
	/// Okno renderowania gry.
	sf::RenderWindow window;
	///Tryb wideo uzywany w grze.
	sf::VideoMode videoMode;
	///Kolor tla do czyszczenia ekranu.
	sf::Color clearColor;    
	///Maksymalna liczba klatek na sekunde.
	unsigned int frameLimit;
	///Flaga okreslajaca tryb pelnoekranowy.
	bool fullscreen;
	///Plik logu dla zapisywania bledow.
	ofstream logFile;   
	///Pozycja myszy przy ostatnim ruchu.
	Vector2f lastMousePosition;
	///Aktualny kat obrotu.
	float angle= 90;
	///Flaga do wyœwietlania linii.
	bool showLine = false;
	///Flaga do wyœwietlania linii lamanej.
	bool showPolyline = false;
	///Flaga do wyswietlania wielokatow.
	bool showPolygon = false;
	///Flaga do wyœwietlania elipsy.
	bool showElipse = false;
	///Flaga do wyœwietlania kola.
	bool showCircle = false;
	///Flaga wypelnienia ksztaltu.
	bool fillShape = false;
	///Flaga rotacji obiektow.
	bool rotate = false;
	///Flaga translacji obiektow.
	bool translate = false;
	///Flaga skalowania obiektow.
	bool scale = false;
	///Flaga wyswietlania gracza.
	bool showPlayer = false;
};

