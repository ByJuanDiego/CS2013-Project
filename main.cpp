// On MacOS compile with:
// clang++ -std=c++17 main.cpp -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SFML/Graphics.hpp>

namespace myWindow {
    const char* title = "Project";
    constexpr int modeWidth = 800;
    constexpr int modeHeight = 600;
}

int main() {

    sf::RenderWindow window(sf::VideoMode(myWindow::modeWidth, myWindow::modeHeight), myWindow::title);
    window.setFramerateLimit(60);

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

        // Activate the window for OpenGL rendering
        window.setActive();

        // OpenGL drawing commands go here...

        // End the current frame and display its contents on screen
        window.clear();
        window.display();
    }

    return 0;
}
