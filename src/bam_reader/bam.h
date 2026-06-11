#pragma once

#include <string>
#include <memory>

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
        void close();

    private:
        std::string file_path_;
        std::unique_ptr<htsFile> bam_file_;
        std::unique_ptr<sam_hdr_t> bam_header_;
    };
}
