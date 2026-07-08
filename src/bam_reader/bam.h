#pragma once

#include <string>
#include <memory>
#include <vector>

#include "record.h"

class htsFile;
class sam_hdr_t;

namespace bam_reader
{  
    class Bam 
    {
    public:
        explicit Bam(const std::string& file_path);
        ~Bam();

        void open();
        bool is_open() const;
        std::vector<Record> read(uint32_t head_lines = 0) const;

        int32_t get_number_refs() const;
        void close();

    private:
        std::string file_path_;
        std::unique_ptr<htsFile> bam_file_;
        std::unique_ptr<sam_hdr_t> bam_header_;
    };
}
