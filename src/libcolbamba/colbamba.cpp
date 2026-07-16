#include <iostream>
#include <stdexcept>

#include "colbamba.h"
#include "utils.h"

namespace colbamba
{
    void show_records(bam_reader::Bam& reader, uint32_t head_lines)
    {
        if (!reader.is_open())
            throw std::runtime_error("BAM file is not open");

        auto records = reader.read(head_lines);

        for (const auto& record : records)
            std::cout << bam_reader::record_to_string(record) << '\n';
    }
}