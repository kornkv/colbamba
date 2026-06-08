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

if(TARGET PkgConfig::HTSLIB)
	target_link_libraries(Combamba PRIVATE PkgConfig::HTSLIB)
else()
	find_path(HTSLIB_INCLUDE_DIR htslib/hts.h)
	find_library(HTSLIB_LIBRARY NAMES hts REQUIRED)
	if(HTSLIB_INCLUDE_DIR)
		target_include_directories(Combamba PRIVATE ${HTSLIB_INCLUDE_DIR})
	endif()
	target_link_libraries(Combamba PRIVATE ${HTSLIB_LIBRARY})
endif()

