#pragma once
#include "UpdatableObject.h"
#include <SFML/System/Vector2.hpp>
/// Klasa abstrakcyjna reprezentujaca obiekt, ktory moze byc transformowany.
/// 
/// Klasa ta dziedziczy po klasie UpdatableObject, dzieki czemu obiekt mo¿e byc aktualizowany 
/// w czasie.Dodatkowo oferuje funkcje umo¿liwiajace wykonywanie operacji transformacji takich jak
/// translacja, rotacja i skalowanie.
class TransformableObject : public virtual UpdatableObject
{
public:
	/// Konstruktor domyslny obiektu TransformableObject.
	/// 
	/// Inicjalizuje obiekt w sposob standardowy. Konkretne ustawienia obiektu s¹ zalezne od klasy pochodnej.
	TransformableObject();
	/// Przesuwa obiekt o okreslony wektor translacji.
	/// 
	/// Funkcja ta pozwala na przesuniecie obiektu o wektor translacji.
	/// <param name="translationVector">Wektor o ktorym obiekt zostanie przesuniety.</param>
	virtual void translate(sf::Vector2f translationVector) = 0;
	/// Rotuje obiekt o okreslony kat wokol zadanego punktu.
	/// 
	/// Funkcja ta pozwala na obrocenie obiektu o zadana liczbe stopni wokol zadanego punktu.
	/// <param name="angle">Kat obrotu w stopniach.</param>
	/// <param name="center">Punkt, wokol ktorego obiekt ma zostac obrocony.</param>
	virtual void rotate(float angle, const sf::Vector2f& center) = 0;
	///  Skaluje obiekt o zadany wspolczynnik wokol zadanego punktu.
	/// 
	/// Funkcja ta pozwala na zmiane rozmiaru obiektu przez skalowanie w oparciu o punkt centrum.
	/// <param name="factor">Wspolczynnik skalowania.</param>
	/// <param name="center">Punkt, wokol ktorego obiekt ma zostac skalowany.</param>
	virtual void scale(float factor, const sf::Vector2f& center) = 0;
};

