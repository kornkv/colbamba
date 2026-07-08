#pragma once

#include <string>

namespace bam_reader
{
    struct Record
    {
        std::string qname;
        int32_t flag;
        std::string rname;
        int64_t pos;
        int32_t mapq;
        std::string cigar;
        std::string rnext;
        int64_t pnext;
        int64_t tlen;
    };
}