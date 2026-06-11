#include "bam.h"

#include <htslib/sam.h>

#include <stdexcept>
#include <filesystem>

namespace bam_reader
{
    Bam::Bam(const std::string& file_path)
        : file_path_(file_path)
    {
    }

    Bam::~Bam()
    {
        close();
    }

    void Bam::open()
    {
        if (!std::filesystem::exists(file_path_))
            throw std::runtime_error("BAM file " + file_path_ + " does not exist");

        bam_file_.reset(sam_open(file_path_.c_str(), "r"));
        if (!bam_file_)
            throw std::runtime_error("Failed to open BAM file: " + file_path_);

        bam_header_.reset(sam_hdr_read(bam_file_.get()));
        if (!bam_header_)
            throw std::runtime_error("Failed to read BAM header: " + file_path_);
    }

    void Bam::close()
    {
        if (bam_file_)
            sam_close(bam_file_.release());
        
        if (bam_header_)
            bam_hdr_destroy(bam_header_.release());
    }
}