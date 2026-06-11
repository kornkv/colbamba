add_executable(Combamba main.cpp)

set_target_properties(Combamba PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

target_link_libraries(Combamba PRIVATE Boost::program_options)

if(TARGET PkgConfig::BIGWIG)
	target_link_libraries(Combamba PRIVATE PkgConfig::BIGWIG)
else()
	find_path(BIGWIG_INCLUDE_DIR bigWig.h)
	find_library(BIGWIG_LIBRARY NAMES BigWig bigwig REQUIRED)
	if(BIGWIG_INCLUDE_DIR)
		target_include_directories(Combamba PRIVATE ${BIGWIG_INCLUDE_DIR})
	endif()
	target_link_libraries(Combamba PRIVATE ${BIGWIG_LIBRARY})
endif()

add_subdirectory(bam_reader)

