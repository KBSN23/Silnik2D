#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
/// Klasa reprezentujaca obiekt ksztaltu.
/// 
/// Klasa `ShapeObject` dziedziczy wirtualnie z `DrawableObject` i `TransformableObject`.
/// Umozliwia polaczenie funkcjonalnosci rysowania i transformacji w obiektach graficznych
/// opartych na ksztaltach, takich jak prostokaty, okregi czy wielokaty.
class ShapeObject : public virtual DrawableObject, public virtual TransformableObject
{
public:
	/// Konstruktor domyslny klasy ShapeObject.
	/// 
	/// Tworzy obiekt `ShapeObject` i inicjalizuje jego bazowe wlasciwosci.
	ShapeObject();
};

