cmake_minimum_required(VERSION 3.30.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    nusantara
    VERSION 1.0.0
    DESCRIPTION "Indonesian Programming Language"
    LANGUAGES CXX
)

include_directories("include")

file(
    GLOB_RECURSE
    SRC_FILES
    "src/**/*.cc"
    "src/*.cc"
)

add_executable(
    nusantara
    ${SRC_FILES}
)