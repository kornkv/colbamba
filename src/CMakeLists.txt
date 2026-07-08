add_executable(Colbamba 
	main.cpp
)

set_target_properties(Colbamba PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

target_link_libraries(Colbamba PRIVATE 
	Boost::program_options
	bam_reader
	colbamba)

if(TARGET PkgConfig::BIGWIG)
	target_link_libraries(Colbamba PRIVATE PkgConfig::BIGWIG)
else()
	find_path(BIGWIG_INCLUDE_DIR bigWig.h)
	find_library(BIGWIG_LIBRARY NAMES BigWig bigwig REQUIRED)
	if(BIGWIG_INCLUDE_DIR)
		target_include_directories(Colbamba PRIVATE ${BIGWIG_INCLUDE_DIR})
	endif()
	target_link_libraries(Colbamba PRIVATE ${BIGWIG_LIBRARY})
endif()

add_subdirectory(bam_reader)
add_subdirectory(colbamba)

