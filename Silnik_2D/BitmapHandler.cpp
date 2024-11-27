#include "BitmapHandler.h"
/// Tworzy obraz o podanych rozmiarach i kolorze tla.
/// 
/// <param name="width">Szerokosc obrazu.</param>
/// <param name="height">Wysokosc obrazu.</param>
/// <param name="color">Kolor tla obrazu.</param>
void BitmapHandler::create(unsigned int width, unsigned int height, const sf::Color& color ) {
    image.create(width, height, color);
    texture.loadFromImage(image);
}
/// Laduje obraz do pliku.
/// 
/// <param name="filename">Nazwa pliku do zaladowania.</param>
void BitmapHandler::loadFromFile( std::string& filename) {
    image.loadFromFile(filename);
    texture.loadFromImage(image);
}
/// Czysci obraz, tworzac nowy o tych samych rozmiarach i podanym kolorze tla.
/// 
/// <param name="color">Kolor tla do uzycia przy czyszczeniu obrazu.</param>
void BitmapHandler::clear(const sf::Color& color) {
    create(image.getSize().x, image.getSize().y, color);
}
/// Wyswietla obraz na oknie renderowania w okreslonej pozycji. 
///
/// <param name="window">Okno rendowania.</param>
/// <param name="pos">Pozycja na ekranie, w ktorej ma byc wyswietlony obraz.</param>
void BitmapHandler::display(sf::RenderWindow& window, sf::Vector2f pos) {
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(0.4f, 0.4f);
    window.draw(sprite);
}
///Obraz przechowywany w klasie BitmapHandler.
sf::Image BitmapHandler::image;
/// Tekstura powiazana z obrazem.
sf::Texture BitmapHandler::texture;
/// Sprite powiazany z tekstura.
sf::Sprite BitmapHandler::sprite;