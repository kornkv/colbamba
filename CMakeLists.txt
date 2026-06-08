cmake_minimum_required(VERSION 3.15)
project(Colmbamba)

find_package(Boost REQUIRED COMPONENTS program_options)

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
	pkg_check_modules(BIGWIG QUIET IMPORTED_TARGET libBigWig)
endif()

add_subdirectory(src)