add_executable(tests test_bam_to_bigwig.cpp)

target_compile_definitions(tests PRIVATE
    TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test_data")

target_link_libraries(tests PRIVATE 
    Boost::unit_test_framework
    bam_reader 
    colbamba)


target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME tests COMMAND tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})