// On MacOS compile with:
// clang++ -std=c++17 main.cpp -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SFML/Graphics.hpp>

namespace myWindow {
    const char* title = "Project";
    constexpr unsigned int modeWidth = 800;
    constexpr unsigned int modeHeight = 800;
}

namespace shapeSizes{
    constexpr float radius = 200;
}

int main() {

    sf::RenderWindow window(sf::VideoMode(myWindow::modeWidth, myWindow::modeHeight), myWindow::title);
    window.setFramerateLimit(60);

    sf::CircleShape shape(shapeSizes::radius);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen()){

        // Event processing
        sf::Event event {};
        while (window.pollEvent(event)){

            // ---------------
            switch (event.type) {

                // Request for closing the window
                case sf::Event::Closed:
                    window.close();
                    std::cout << "Window Closed" << std::endl;
                    break;
                default:
                    break;
            }
        }

        // Clear Window
        window.clear();

        // Draw Shapes
        window.draw(shape);

        // End the current frame and display its contents on screen
        window.display();
    }

    return 0;
}
