cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NCPP_UNIT_TEST ON)

project(
	ncpp
	VERSION 1.0.0
	DESCRIPTION "Nusantara library untuk c++"
	LANGUAGES CXX
)

file(
	GLOB_RECURSE 
	SOURCES
	"src/ncpp/*.cc"
	"src/ncpp/**/*.cc"
)

include_directories(include)

add_library(
	${PROJECT_NAME} 
	STATIC
	${SOURCES}
)


target_link_libraries(
	ncpp
	PRIVATE
	gmp
	mpfr
)
	
target_include_directories(ncpp PUBLIC ${PROJECT_SOURCE_DIR}/include)
	
if(${NCPP_UNIT_TEST} STREQUAL "ON")
	message(STATUS "Unit Test (ON)")
	add_subdirectory(test)
	set(INSTALL_TEST_DIR ${CMAKE_INSTALL_PREFIX}/bin)
	install(TARGETS ncpp_test
		DESTINATION ${INSTALL_TEST_DIR}
	)
else()
	message(STATUS "Unit Test (OFF)")
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)

install(TARGETS ncpp
	LIBRARY DESTINATION ${INSTALL_DIR}
	ARCHIVE DESTINATION ${INSTALL_DIR}
)

target_include_directories(ncpp PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX})
	install(DIRECTORY include
	DESTINATION ${INSTALL_INCLUDE_DIR}
)
