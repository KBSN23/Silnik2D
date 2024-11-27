#include "ShapeObject.h"
/// Konstruktor domyslny klasy ShapeObject.
/// 
/// Klasa `ShapeObject` dziedziczy z `TransformableObject` i `DrawableObject`.
/// Konstruktor inicjalizuje obiekty bazowe, zapewniajac podstawowe funkcjonalnosci
/// transformacji i rysowania dla obiektow ksztaltow w grze.
ShapeObject::ShapeObject() : TransformableObject(), DrawableObject() {

}