cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")

if (WIN32)
	message(STATUS "Platform : Windows")
	set(NCPP_INCLUDE_DIR "C:/Aerell/App/ncpp/include")
	set(NCPP_LIB "C:/Aerell/App/ncpp/lib/libncpp.a")
elseif(UNIX)
	message(STATUS "Platform : Linux")
endif()

project(
	main
)

file(
	GLOB_RECURSE
	SRC_FILES
	"src/*.cc"
	)
	
add_executable(
	main
	${SRC_FILES}
)

if(WIN32)
	target_include_directories(
		main
		PUBLIC
		${NCPP_INCLUDE_DIR}
	)
	target_link_libraries(
		main
		PRIVATE
		gmp
		mpfr
		${NCPP_LIB}
	)
elseif(UNIX)
	target_link_libraries(
		main
		PRIVATE
		gmp
		mpfr
		ncpp
	)
endif()