cmake_minimum_required(VERSION 3.17)
project(YellowBelt_final)

set(CMAKE_CXX_STANDARD 17)

add_executable(YellowBelt_final
        main.cpp
        condition_parser.h condition_parser.cpp condition_parser_test.cpp
        token.h token.cpp
        database.cpp database.h database_test.cpp
        date.cpp date.h date_test.cpp
        node.cpp node.h node_test.cpp
        test_runner.cpp test_runner.h event_set.cpp event_set.h)