//
// Created by Juan Diego Castro Padilla on 5/05/22.
//

#ifndef CS2013_PROJECT_DEFINITIONS_H
#define CS2013_PROJECT_DEFINITIONS_H

// C++ Standard Libraries
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <functional>

// Third-party library
#include <SFML/Graphics.hpp>

namespace Type{
    typedef const char* str;
    typedef unsigned int int_u;
}

struct myWindow {
    constexpr inline static Type::str title = "SFML Prog3 Project";
    constexpr inline static Type::int_u modeWidth = 600;
    constexpr inline static Type::int_u modeHeight = 600;
};


#endif //CS2013_PROJECT_DEFINITIONS_H
