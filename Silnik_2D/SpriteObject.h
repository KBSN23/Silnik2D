#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
/// Klasa reprezentujaca obiekt sprite'u, ktory laczy funkcjonalnosci obrazu bitmapowego oraz animacji.
/// 
/// Klasa dziedziczy po klasach BitmapObject i AnimatedObject, dziêki czemu obiekt sprite'u 
/// moze zarowno wyswietlac statyczny obraz, jak i obslugiwac animacje.
class SpriteObject : public virtual BitmapObject, public virtual AnimatedObject
{
};

