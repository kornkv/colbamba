# colbamba

C++ tool for generating CPM-normalized BigWig coverage tracks from 
collapsed small RNA-seq BAM files.

## Background

In small RNA-seq pipelines, identical reads are often collapsed before 
alignment to reduce redundancy. The original read count is encoded in 
the read name (e.g. `387699-1`, `223894-3`). Standard coverage tools 
treat each alignment as a single read, producing incorrect results for 
collapsed BAMs. colbamba parses the count from the read name and 
weights coverage accordingly.

## Features

- Count-aware coverage: reads the original molecule count from QNAME
- CPM normalization
- Strand-specific output
- BigWig and BedGraph output
- Per-sample alignment statistics

## Status

🚧 starting development

## License

MIT
