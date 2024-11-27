#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
/// Klasa reprezentujaca obiekt bitmapowy.
/// 
/// Klasa `BitmapObject` dziedziczy wirtualnie z `DrawableObject` i `TransformableObject`.
/// Laczy funkcjonalnosci obiektow, ktore mozna rysowac oraz transformowac.
/// Jest przeznaczona do reprezentowania bitmap w aplikacji, umozliwiajac ich rysowanie
/// oraz modyfikacje polozenia, rotacji, czy skalowania
class BitmapObject : public virtual DrawableObject , public virtual TransformableObject
{

};

