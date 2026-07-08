#pragma once

#include "bam.h"

namespace colbamba
{
    void show_records(const bam_reader::Bam& reader, uint32_t head_lines);
}