CMAKE_minimum_required(VERSION 3.20)

project(Jogo2D LANGUAGES CXX)

set(CMAKE_XX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)


find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)

find_package(SDL2_ttf REQUIRED)

find_package(SDL2_mixer REQUIRED)

find_package(nlohmann_json REQUIRED)

add_executable(jogo2D WIN32
src/main.cpp
)


target_include_directories(jogo2D PRIVATE
SDL2::SDL2
SDL2::SDL2main
SDL2::SDL2_image
SDL2::SDL2_ttf
SDL2::SDL2_mixer
nlohmann_json::nlohmann_json

)