add_executable(colbamba 
	main.cpp
)

set_target_properties(colbamba PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

target_link_libraries(colbamba PUBLIC
	Boost::program_options
	bam_reader
	libcolbamba)

if(TARGET PkgConfig::BIGWIG)
	target_link_libraries(colbamba PRIVATE PkgConfig::BIGWIG)
else()
	find_path(BIGWIG_INCLUDE_DIR bigWig.h)
	find_library(BIGWIG_LIBRARY NAMES BigWig bigwig REQUIRED)
	if(BIGWIG_INCLUDE_DIR)
		target_include_directories(colbamba PRIVATE ${BIGWIG_INCLUDE_DIR})
	endif()
	target_link_libraries(colbamba PRIVATE ${BIGWIG_LIBRARY})
endif()

add_subdirectory(bam_reader)
add_subdirectory(libcolbamba)

