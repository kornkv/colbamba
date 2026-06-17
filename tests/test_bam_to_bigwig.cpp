#define BOOST_TEST_MODULE test_bam_to_bigwig

#include <boost/test/unit_test.hpp>

#include "bam_reader/bam.h"

const std::string test_bam_file = std::string(TEST_DATA_DIR) + "/scaffold_28.bam";

BOOST_AUTO_TEST_CASE(test_bam_to_bigwig)
{
    bam_reader::Bam bam_file(test_bam_file);
    bam_file.open();
}