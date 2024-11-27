#include <SFML/Graphics.hpp>
#include "engine.h"
#include <stdio.h>

using namespace std;
int main() {
    Engine engine(800, 600, sf::Color::Black, 60,false);

    cout << "Instrukcja Obslugi:" << endl;
    cout << "1 - Rysowanie Lini" << endl;
    cout << "2 - Przemieszczenie " << endl;
    cout << "3 - Rosowanie okręgu " << endl;
    cout << "4 - Wypelnianie kolorem" << endl;
    cout << "5 - Ryswanie lini lamanej" << endl;
    cout << "6 - Rysowanie wielokatu " << endl;
    cout << "7 - Rysowanie elipsy" << endl;
    cout << "8 - Rotacja " << endl;
    cout << "9 - Skalowanie" << endl;
    cout << "0 - Bitmapy DEMO" << endl;



    if (!engine.initialize()) {
        return -1;
    }
    engine.run(); 

    return 0;
}