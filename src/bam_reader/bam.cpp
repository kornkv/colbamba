#include "bam.h"
#include "utils.h"

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

    bool Bam::is_open() const
    {
        return bam_file_ != nullptr && bam_header_ != nullptr;
    }

    std::vector<Record> Bam::read(uint32_t head_lines) const
    {
        if (!bam_file_)
            throw std::runtime_error("BAM file is not open");

        std::vector<Record> records;
        if (head_lines == 0)
            head_lines = get_number_refs();

        records.reserve(head_lines);

        for (uint32_t i = 0; i < head_lines; ++i) {
            bam1_t* rec = bam_init1();
            int code = sam_read1(bam_file_.get(), bam_header_.get(), rec);
            if (code < 0) {
                bam_destroy1(rec);
                throw std::runtime_error("Failed to read BAM record");
            }

            int32_t mtid = rec->core.mtid;

            records.emplace_back(Record{
                .qname = std::string(bam_get_qname(rec)),
                .flag  = rec->core.flag,
                .rname = std::string(bam_header_->target_name[rec->core.tid]),
                .pos   = rec->core.pos + 1, // Convert to 1-based position
                .mapq  = rec->core.qual,
                .cigar = get_cigar_string(rec, rec->core.n_cigar),
                .rnext = (mtid >= 0) ? std::string(sam_hdr_tid2name(bam_header_.get(), mtid)) : "*",
                .pnext = rec->core.mpos + 1, // Convert to 1-based position
                .tlen  = rec->core.isize
            });
            bam_destroy1(rec);
        }
        return records;
    }

    int32_t Bam::get_number_refs() const
    {
        if (!bam_header_)
            throw std::runtime_error("BAM file is not open");

        return bam_header_->n_targets;
    }

    void Bam::close()
    {
        if (bam_file_)
            sam_close(bam_file_.release());
        
        if (bam_header_)
            bam_hdr_destroy(bam_header_.release());
    }
}