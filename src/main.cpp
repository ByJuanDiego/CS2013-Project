// On MacOS compile with:
//  clang++ -std=c++17 src/main.cpp src/Game.cpp src/Board.cpp src/AI.cpp -L/usr/local/lib/ -o prog -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && mv prog bin/

#include "Game.h"

int main(){
    AI gameAI;
    Game hexGame(gameAI);
    std::srand(std::time(nullptr));
    hexGame.play();
    return 0;
}

//int main(){
//
//    sf::RenderWindow window (sf::VideoMode(myWindow::modeWidth,myWindow::modeHeight),myWindow::title);
//    window.setFramerateLimit(60);
//
//    // Load a font, and setup a test 'text' for us
//    sf::Font font;
//    font.loadFromFile("./assets/fonts/comicate.ttf");
//    sf::Text text("SFML", font, 40);
//    text.move(250.0f, 0.0f);
//
//    sf::Texture texture;
//    texture.loadFromFile("./assets/images/wood.jpg");
//    // Setup our sprite with a texture
//    sf::Sprite sprite(texture);
//
//    sprite.setScale(1.0f, 1.0f);
//
//    float xPosition = 0.0f;
//
//    // Main application loop
//    while (window.isOpen()){
//
//        sf::Event event {};
//        // Handle events
//        while (window.pollEvent(event)){
//
//            switch (event.type) {
//
//                // Terminate application
//                case sf::Event::Closed:
//                    window.close();
//                    std::cout << "Handling event closed" << std::endl;
//                    exit(EXIT_SUCCESS);
//
//                case sf::Event::KeyPressed:
//                    switch (event.key.code) {
//                        case sf::Keyboard::Escape:
//                            window.close();
//                            std::cout << "Handling event closed" << std::endl;
//                            exit(EXIT_SUCCESS);
//                        default:
//                            break;
//                    }
//
//                default:
//                    break;
//            }
//        }
//
//        sprite.setPosition(xPosition, 0.0f);
//        xPosition += 1;
//        if (xPosition >= static_cast<float>(myWindow::modeWidth - texture.getSize().x)){
//            xPosition = 0.0f;
//        }
//
//        // Clear Window
//        window.clear();
//        // Draw Sprites
//        window.draw(sprite);
//        // Draw Our Text
//        window.draw(text);
//        // Finally we display and put forth our graphics scene
//        window.display();
//    }
//
//    return 0;
//}
