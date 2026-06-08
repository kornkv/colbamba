#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

int main(int argc, const char* argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(), "input BAM file")
        ("output,o", po::value<std::string>(), "output BigWig file");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("input") == 0 || vm.count("output" ) == 0) {
        std::cout << "Input and output files must be specified.\n";
        return 1;
    }

    std::string input_file = vm["input"].as<std::string>();
    std::string output_file = vm["output"].as<std::string>();
    std::cout << "Input file: " << input_file << "\n";
    std::cout << "Output file: " << output_file << "\n";

    return 0;
}