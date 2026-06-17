cmake_minimum_required(VERSION 3.15)
project(colbamba)

find_package(Boost REQUIRED COMPONENTS program_options unit_test_framework)

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
	pkg_check_modules(BIGWIG QUIET IMPORTED_TARGET libBigWig)
	pkg_check_modules(HTSLIB QUIET IMPORTED_TARGET htslib)
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)