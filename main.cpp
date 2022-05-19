// On MacOS compile with:
//  clang++ -std=c++17 main.cpp src/Game.cpp src/Board.cpp src/AI.cpp -L/usr/local/lib/ -o prog -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#include "include/Game.h"

//int main(){
//    std::srand(std::time(nullptr));
//    AI gameAI;
//    Game hexGame(gameAI);
//    hexGame.play();
//    return 0;
//}

int main(){

    sf::RenderWindow window (sf::VideoMode(myWindow::modeWidth,myWindow::modeHeight),myWindow::title);
    window.setFramerateLimit(60);

    sf::CircleShape octagon(80, 6);
    octagon.setFillColor(sf::Color::Blue);

    // Load a font, and setup a test 'text' for us
    sf::Font font;
    font.loadFromFile("./assets/fonts/comicate.ttf");
    sf::Text text("SFML", font, 40);
    text.move(250.0f, 0.0f);

    sf::Texture texture;
    texture.loadFromFile("./assets/images/map.png");
    // Setup our sprite with a texture
    sf::Sprite sprite(texture);
    sprite.setScale(1.5f, 1.5f);

    // Main application loop
    while (window.isOpen()){

        sf::Event event {};
        // Handle events
        while (window.pollEvent(event)){

            switch (event.type) {

                // Terminate application
                case sf::Event::Closed:
                    window.close();
                    std::cout << "Handling event closed" << std::endl;
                    exit(EXIT_SUCCESS);

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                            std::cout << "Handling event closed" << std::endl;
                            exit(EXIT_SUCCESS);
                        default:
                            break;
                    }

                default:
                    break;
            }
        }

        // Clear Window
        window.clear();
        // Draw Sprites
        window.draw(sprite);
        window.draw(octagon);
        // Draw Our Text
        window.draw(text);
        // Finally we display and put forth our graphics scene
        window.display();

    }

    return 0;
}
