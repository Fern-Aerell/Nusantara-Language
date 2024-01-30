cmake_minimum_required(VERSION 3.27.4)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
	nusantara
	VERSION 1.0.0
	DESCRIPTION "Sebuah alat command-line untuk Nusantara development."
	LANGUAGES CXX
)

include_directories(include)

file(
	GLOB
	SRC_FILES
	"src/*.c"
	"src/*.cc"
	"src/*.cpp"
)

add_executable(
	nusantara
	${SRC_FILES}
)
