#pragma once
#include <SFML/Graphics.hpp>
///  Klasa bazowa dla obiektow animowanych.
/// 
/// Klasa `AnimatedObject` definiuje interfejs dla obiektow, ktore maja mozliwosc animacji.
/// Zawiera metode wirtualna czysto abstrakcyjna `animate`, ktora musi zostac zaimplementowana
/// w klasach pochodnych.
class AnimatedObject
{
public:
	/// Wirtualna metoda odpowiedzialna za animacje obiektu.
	/// 
	/// Metoda ta powinna zostac zaimplementowana w klasach dziedziczacych
	///	i zawierac logike animacji oparta na zegarze SFML.
	/// <param name="clock">Clock sluzacy do kontrolowania czasu animacji.</param>
	virtual void animate(sf::Clock clock) = 0;
};

