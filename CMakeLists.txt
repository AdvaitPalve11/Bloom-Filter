cmake_minimum_required(VERSION 3.20)

project(BloomFilter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BloomFilter
    main.cpp)

target_compile_options(BloomFilter PRIVATE -Wall -Wextra)
