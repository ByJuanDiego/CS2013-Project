//
// Created by Juan Diego Castro Padilla on 5/05/22.
//

#ifndef CS2013_PROJECT_DEFINITIONS_H
#define CS2013_PROJECT_DEFINITIONS_H


namespace Type{
    typedef const char* str;
    typedef unsigned int int_u;
    typedef short int int_s;
    typedef long int int_l;
}

struct myWindow {
    constexpr inline static Type::str title = "My Project";
    constexpr inline static Type::int_u modeWidth = 320;
    constexpr inline static Type::int_u modeHeight = 319;
};


#endif //CS2013_PROJECT_DEFINITIONS_H
