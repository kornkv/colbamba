add_library(bam_reader 
	bam.cpp
)

target_include_directories(bam_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(TARGET PkgConfig::HTSLIB)
	target_link_libraries(bam_reader PUBLIC PkgConfig::HTSLIB)
else()
	find_path(HTSLIB_INCLUDE_DIR htslib/hts.h)
	find_library(HTSLIB_LIBRARY NAMES hts REQUIRED)
	if(HTSLIB_INCLUDE_DIR)
		target_include_directories(bam_reader PUBLIC ${HTSLIB_INCLUDE_DIR})
	endif()
	target_link_libraries(bam_reader PUBLIC ${HTSLIB_LIBRARY})
endif()