add_library(colbamba colbamba.cpp)

target_include_directories(colbamba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(colbamba PRIVATE bam_reader)