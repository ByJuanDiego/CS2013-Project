cmake_minimum_required(VERSION 3.21)
project(CS2013_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp img/wood.jpg)
add_executable(CS2013_Project ${SOURCE_FILES})

if (APPLE)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

    if(SFML_FOUND)
        message("SFML FOUND")
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(CS2013_Project sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
    endif()

elseif(WIN32)

    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR C:/SFML/lib/cmake/SFML)

    find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

    include_directories(C:/SFML/include)
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics -static sfml-audio)

endif()
