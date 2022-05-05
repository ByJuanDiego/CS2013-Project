cmake_minimum_required(VERSION 3.21)
project(CS2013_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (APPLE)

    message("MacOS detected")
    include_directories(/usr/local/include)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

elseif(WIN32)

    message("Windows 32 detected")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR C:/SFML/lib/cmake/SFML)

    find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

    include_directories(C:/SFML/include)
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics -static sfml-audio)

endif()
