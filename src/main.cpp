#include <boost/program_options.hpp>
#include <iostream>

#include "libcolbamba/colbamba.h"

namespace po = boost::program_options;

int main(int argc, const char* argv[])
{
    po::options_description desc("Allowed options");
    bool read_all = false;
    desc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(), "input BAM file")
        ("head,n", po::value<uint32_t>()->default_value(10), "number of records to read")
        ("all,a", po::bool_switch(&read_all), "read all records");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << '\n';
        return 1;
    }

    if (vm.count("input") == 0) {
        std::cout << "Input file must be specified.\n";
        return 1;
    }

    std::string input_file = vm["input"].as<std::string>();
    uint32_t head_lines = vm["head"].as<uint32_t>();

    bam_reader::Bam bam_file(input_file);
    try {
        bam_file.open();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error opening BAM file: " << e.what() << '\n';
        return 1;
    }

    if (!bam_file.is_open()) {
        std::cerr << "Failed to open BAM file: " << input_file << '\n';
        return 1;
    }

    colbamba::show_records(bam_file, head_lines);

    return 0;
}