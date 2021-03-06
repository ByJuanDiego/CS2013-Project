//
// Created by Juan Diego Castro Padilla on 5/05/22.
//

#ifndef CS2013_PROJECT_DEFINITIONS_H
#define CS2013_PROJECT_DEFINITIONS_H

//C++ Standard Libraries {{{1
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <array>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <utility>

//Third-party Libraries {{{1
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

//Namespaces {{{1
namespace type {
    typedef const char* str;
    typedef unsigned int int_u;
}

//Structs {{{1
struct myWindow {
    constexpr inline static type::str title = "SFML Prog3 Project";
    constexpr inline static type::int_u modeWidth = 1263;
    constexpr inline static type::int_u modeHeight = 960;
};

//Enums {{{1
enum class Player {
    WHITE, BLACK
};

#endif //CS2013_PROJECT_DEFINITIONS_H
