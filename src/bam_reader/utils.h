#pragma once

#include <string>
#include <cstdint>

#include <htslib/sam.h>

#include "record.h"

namespace bam_reader
{

    static inline std::string get_cigar_string(const bam1_t* rec)
    {
        uint32_t* cigar = bam_get_cigar(rec);
        std::string cigar_str;

        for (uint32_t j = 0; j < rec->core.n_cigar; ++j) {
            uint32_t op_len = bam_cigar_oplen(cigar[j]);
            uint32_t opchr = bam_cigar_opchr(cigar[j]);

            cigar_str += std::to_string(op_len) + static_cast<char>(opchr);
        }
        return cigar_str;
    }

    static inline std::string record_to_string(const Record& rec)
    {
        return rec.qname + "\t" +
               std::to_string(rec.flag) + "\t" + 
               rec.rname + "\t" +
               std::to_string(rec.pos) + "\t" +
               std::to_string(rec.mapq) + "\t" + 
               rec.cigar + "\t" +
               rec.rnext + "\t" +
               std::to_string(rec.pnext) + "\t" +
               std::to_string(rec.tlen);
    }
}