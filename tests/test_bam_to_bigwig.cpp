#define BOOST_TEST_MODULE test_bam_to_bigwig

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "bam_reader/bam.h"
#include "libcolbamba/colbamba.h"

const std::string test_bam_file = std::string(TEST_DATA_DIR) + "/scaffold_28.bam";

struct cout_redirect {
    cout_redirect(std::streambuf* new_buffer) 
        : old_buffer(std::cout.rdbuf(new_buffer)) {}

    ~cout_redirect() { 
        std::cout.rdbuf(old_buffer); 
    }

private:
    std::streambuf* old_buffer;
};

BOOST_AUTO_TEST_CASE(test_bam_to_bigwig)
{
    bam_reader::Bam bam_file(test_bam_file);
    bam_file.open();
    auto records = bam_file.read(5);
    boost::test_tools::output_test_stream captured_output;
    {
        cout_redirect redirect(captured_output.rdbuf());
        colbamba::show_records(bam_file, 5);
    }
    BOOST_REQUIRE_EQUAL(records.size(), 5u);
    BOOST_TEST(captured_output.is_equal(
        "VH01079:66:AAF3WNGM5:1:1309:37527:39110\t16\tscaffold_28\t14157\t255\t27M\t*\t0\t0\n"
        "VH01079:66:AAF3WNGM5:1:2302:70929:46493\t16\tscaffold_28\t14167\t255\t28M\t*\t0\t0\n"
        "VH01079:66:AAF3WNGM5:1:1306:62408:48273\t16\tscaffold_28\t14174\t255\t29M\t*\t0\t0\n"
        "VH01079:66:AAF3WNGM5:1:1403:19405:7096\t16\tscaffold_28\t14192\t255\t27M\t*\t0\t0\n"
        "VH01079:66:AAF3WNGM5:1:1403:19405:7248\t16\tscaffold_28\t14192\t255\t27M\t*\t0\t0\n"
    ));
}