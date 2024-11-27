#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "Player.h"
#include "BitmapHandler.h"
/// Konstruktor klasy Engine, inicjalizuje parametry okna gry.
/// 
/// <param name="window_width">Szerokosc okna.</param>
/// <param name="window_height">Wysokosc okna.</param>
/// <param name="clear_color">Kolor t³a okna.</param>
/// <param name="frame_limit">Limit liczby klatek na sekunde.</param>
/// <param name="full_screen">Flaga mowiaca o tym ze program dziala w trybie pelnego ekranu.</param>
Engine::Engine(unsigned int window_width, unsigned int window_height,sf::Color clear_color, unsigned int frame_limit,bool full_screen) :
    videoMode(window_width, window_height), 
    clearColor(clear_color), 
    frameLimit(frame_limit), 
    fullscreen(full_screen) 
{
   //Proba otworzenia pliku
    logFile.open("engine.log", ios::out | ios::app);
    if (!logFile.is_open()) {
        cerr << "Nie udalo siê otworzyc pliku logu!" << endl;
    }
}
///Destruktor klasy Engine wykonujacy czyszczenie zasobow.
Engine::~Engine() {
    cleanup();
    logFile.close();
}
/// Inicjalizuje okno gry, ustawia limit klatek na sekunde oraz sprawdza, czy okno zostalo poprawnie utworzone.
/// 
/// <returns>Zwraca true, jesli inicjalizacja zakonczyla siê sukcesem, w przeciwnym razie false.</returns>
bool Engine::initialize() {
   
    if (fullscreen) {
        window.create(videoMode, "Silnik2D", sf::Style::Fullscreen);
    }
    else {
        window.create(videoMode, "Silnik2D", sf::Style::Close);
    }

  
    window.setFramerateLimit(frameLimit);

    if (!window.isOpen()) {
        logError("Nie uda³o siê utworzyæ okna!");
        return false;
    }

    return true;
}
/// Glowna petla gry. Przechodzi przez zdarzenia, aktualizuje stan gry i renderuje grafike.
void Engine::run() {
    sf::Clock clock;
    int currentFrame = 0;
    float frameDuration = 2.0f;
    //Tworzenie obiektu gracza
	Player player(Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D);



    while (window.isOpen()) {
        if (clock.getElapsedTime().asSeconds() > frameDuration) {
            clock.restart();
        }
        events(player);
        update();
        render(player, clock); 
    }
}
/// Obs³uguje zdarzenia  
/// 
/// <param name="player">Obiekt gracza ktory moze byc zmieniany</param>
void Engine::events(Player& player) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();///< Zamkniêcie okna.
        }
        // Obs³uga klawiszy gracza
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close(); // Zamkniêcie okna.
            }

            if (event.mouseButton.button == player.leftKey) {
                player.moveLeft();
            }

            if (event.mouseButton.button == player.rightKey) {
                player.moveRight();
            }

            if (event.mouseButton.button == player.upKey) {
                player.moveUp();
            }
            // Obsluga klawiszy do zmiany parametrow rysowania.
            if (event.mouseButton.button == player.downKey) {
                player.moveDown();
            }

			if (event.key.code == sf::Keyboard::Num1) {
                showLine = !showLine;
			}
            if (event.key.code == sf::Keyboard::Num2) {
                
                translate = !translate;
            }
            if (event.key.code == sf::Keyboard::Num3) {
                showCircle = !showCircle;
            }
            if (event.key.code == sf::Keyboard::Num4) {
                fillShape = !fillShape;
            }
            if (event.key.code == sf::Keyboard::Num5) {
                showPolyline = !showPolyline;
            }
            if (event.key.code == sf::Keyboard::Num6) {
                showPolygon = !showPolygon;
            }
            if (event.key.code == sf::Keyboard::Num7) {
                showElipse = !showElipse;
            }
            if (event.key.code == sf::Keyboard::Num8) {
                rotate = !rotate;
            }
            if (event.key.code == sf::Keyboard::Num9) {
                scale = !scale;
            }
            if (event.key.code == sf::Keyboard::Num0) {
                showPlayer = !showPlayer;
            }
            if (event.key.code == sf::Keyboard::P) {
                angle+=15; // Zwiekszenie kata obrotu.
            }
            if (event.key.code == sf::Keyboard::O) {
                angle -= 15;// Zmniejszenie kata obrotu.
            }
        }
        // Zatrzymanie ruchu po zwolnieniu klawisza.
        if (event.type == sf::Event::KeyReleased) {
            if (event.mouseButton.button == player.leftKey) {
                player.stop();
            }

            if (event.mouseButton.button == player.rightKey) {
                player.stop();
            }

            if (event.mouseButton.button == player.upKey) {
                player.stop();
            }

            if (event.mouseButton.button == player.downKey) {
                player.stop();
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);
                Point2D p(Vector2f(mousePos.x, mousePos.y), Color::Red);
                p.draw(window);
                window.display();


                std::cout << "Lewy przycisk myszy klikniety na pozycji (" << mousePos.x  << ", " << mousePos.y << ")" << std::endl;
                lastMousePosition=Vector2f(mousePos.x,mousePos.y);
            }

           
        }
    }
}
///Aktualizuje stan gry 
void Engine::update() {
 
}
/// Wykonuje czyszczenie zasobow, zamykajac okno gry, jesli jest otwarte.
void Engine::cleanup() {
    if (window.isOpen()) {
        window.close(); 
    }
}
/// Renderuje wszystkie obiekty na ekranie, w tym gracza i rozne ksztalty.
/// 
/// <param name="player">Obiekt gracza.</param>
/// <param name="clock">Zegar do animacji.</param>
void Engine::render(Player& player, sf::Clock clock) {
   PrimitiveRenderer r(sf::Color::Red);
   
   Point2D p(Vector2f(200, 200), Color::Red);
   vector<Point2D> points = { Point2D(Vector2f(137,448),Color::Green),Point2D(Vector2f(208,519),Color::Green),Point2D(Vector2f(375,528),Color::Green),  Point2D(Vector2f(280,446),Color::Green)};
   vector<LineSegment> segments = { LineSegment(Vector2f(10,350), Vector2f(500,40), Color::Blue, true),LineSegment(Vector2f(10,350), Vector2f(50,460), Color::Blue, true) };


   PrimitiveRenderer::pixelColors = {};
   LineSegment segment(Vector2f(400, 200), Vector2f(400, 250), sf::Color::Cyan, false);
    window.clear(clearColor);




	 if (showPolygon)
	 {
		 r.drawPolygon(window, points);
	 }
	 if (showPolyline)
	 {
		 r.drawPolyline(window, segments);
	 }
     
	if (showElipse) {
		r.drawEllipse(window, Vector2f(601, 500), 50, 100, sf::Color::Red);
	}
	if (showCircle) {
		r.drawCircle(window, Vector2f(400, 400), 100, sf::Color::Cyan);
	}
	if (fillShape && showCircle && !showPlayer)
	{
		r.fill(window, Vector2f(413, 413), sf::Color::Cyan, sf::Color::Cyan);

	}
    if (rotate) {
		segment.rotate(angle, segment.getEdges()[0].getCoords());
    }

    if (translate) {
        segment.translate(lastMousePosition - segment.getEdges()[0].getCoords());
    }

	if (scale) {
		segment.scale(3,segment.getEdges()[0].getCoords());
	}

    if (showLine)
    {
        segment.draw(window);
    }



	if (showPlayer) {
        window.clear();


        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        image.loadFromFile("grafiki/mapa.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(Vector2f(0, 0));
        window.draw(sprite);

        player.animate(clock);
        player.draw(window);
	}

    window.display(); 
}
/// Loguje blad do pliku logu.
/// 
/// <param name="message">Kominikat bledu</param>
void Engine::logError(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
    else {
        std::cerr << "B³¹d: " << message << std::endl;
    }
}