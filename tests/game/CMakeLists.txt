cmake_minimum_required(VERSION 2.8)

enable_testing()

find_package(GTest CONFIG REQUIRED)

file(GLOB src
    *.cpp *.h
    mock/*.cpp mock/*.h
)

add_executable(tests
    ${src}
)

target_link_libraries(tests
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)
