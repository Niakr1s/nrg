cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(entt REQUIRED)
find_package(unofficial-box2d CONFIG REQUIRED)

file(GLOB_RECURSE src
    *.cpp *.h
)

add_executable(game
    ${src}
)

target_include_directories(game
    PUBLIC
    .
    PRIVATE
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(game PRIVATE FLAC OpenAL OpenGL Vorbis
    sfml-window sfml-graphics unofficial::box2d::box2d
)

target_compile_definitions(game PRIVATE ECS_LIBRARY)
