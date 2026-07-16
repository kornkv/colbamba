add_library(libcolbamba colbamba.cpp)

target_include_directories(libcolbamba PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(libcolbamba PUBLIC bam_reader)