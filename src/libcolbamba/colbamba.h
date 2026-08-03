#pragma once

#include "bam.h"

namespace colbamba
{
    void show_records(bam_reader::Bam& reader, uint32_t head_lines, bool read_all = false);
}