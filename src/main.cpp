// On MacOS compile with:
// clang++ -std=c++17 src/main.cpp -L/usr/local/lib/ -o prog -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./prog

#include "definitions.h"

int main(){

    sf::RenderWindow window (sf::VideoMode(myWindow::modeWidth,myWindow::modeHeight),myWindow::title);

    sf::Texture texture;
    texture.loadFromFile("images/wood.jpg");

    sf::Sprite sprite(texture);
    sprite.setScale(1.0f, 1.0f);

    while (window.isOpen()){

        sf::Event event {};
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear Window
        window.clear();

        // Draw Sprites
        window.draw(sprite);

        // Finally we display and put forth our graphics scene
        window.display();
    }

    return EXIT_SUCCESS;
}
