add_library(libcolbamba colbamba.cpp)

target_include_directories(libcolbamba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(libcolbamba PRIVATE bam_reader)