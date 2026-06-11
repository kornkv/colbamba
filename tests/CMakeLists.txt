add_executable(tests test_bam_to_bigwig.cpp)

target_link_libraries(tests PRIVATE bam_reader Boost::unit_test_framework)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME tests COMMAND tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})