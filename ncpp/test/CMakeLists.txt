find_package(GTest QUIET)

enable_testing()

file(
	GLOB_RECURSE
	TEST_FILES
	"src/ncpp_test/*.cc"
)

add_executable(
  ncpp_test
  ${TEST_FILES}
)

target_link_libraries(
  ncpp_test
  ncpp
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ncpp_test)
