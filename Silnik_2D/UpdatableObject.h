#pragma once
#include "GameObject.h"
/// Klasa abstrakcyjna reprezentujaca obiekt, ktory moze byc aktualizowany.
/// 
/// Klasa ta dziedziczy po klasie GameObject, umozliwiajac obiektom aktualizacje ich stanu
/// w ramach gry lub aplikacji.Klasa jest abstrakcyjna, a konkretne implementacje metody update
/// musza zostac zdefiniowane w klasach pochodnych.
class UpdatableObject : public virtual GameObject
{
public:
	///  Konstruktor domyslny obiektu UpdatableObject.
	/// 
	/// Inicjalizuje obiekt w sposob standardowy. Konkretne ustawienia obiektu zaleza od klasy pochodnej.
	UpdatableObject();
	/// Metoda odpowiedzialna za aktualizacje stanu obiektu.
	/// 
	/// Ta metoda musi zostac zaimplementowana w klasach pochodnych, aby umozliwic aktualizacje stanu
	///	obiektu w trakcie dzialania gry lub aplikacji.
	virtual void update() = 0;
};

