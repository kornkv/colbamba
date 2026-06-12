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

## Build

### MacOS project setup

Linux and macOS are both supported platforms. On macOS, you can use VS Code + Dev Containers (this repo already includes `.devcontainer/devcontainer.json`) to match the Linux environment used in CI.

1. Install Docker Desktop and start it.
2. Install VS Code.
3. Install the Dev Containers extension in VS Code.
4. Open this repository in VS Code.
5. Run "Dev Containers: Reopen in Container".
6. Build and test using the Linux commands in this README from inside the container.

Inside the Dev Container, project dependencies are installed automatically when the image is built from `.devcontainer/Dockerfile`.

### Prerequisites

On macOS (before running configure/build commands below):

```bash
brew install cmake boost libbigwig htslib
```

If you use the Dev Container workflow on macOS, first install Docker Desktop, VS Code, and the Dev Containers extension, then reopen the repository in the container. 

On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install -y cmake g++ libboost-program-options-dev libbigwig-dev libhts-dev
```

### Configure and compile

From the repository root:

```bash
cmake -S . -B build
cmake --build build -j
```

The executable is generated at `build/Combamba`.

### Quick check

```bash
./build/Combamba --help
```

## Tests

### Test dependencies

If you are using the Dev Container, test dependencies are installed automatically.

On Debian/Ubuntu, install Boost Unit Test Framework:

```bash
sudo apt update
sudo apt install -y libboost-test-dev
```

If you are setting up from scratch, this project's full dependency set is:

```bash
sudo apt update
sudo apt install -y cmake g++ libboost-program-options-dev libboost-test-dev libbigwig-dev libhts-dev
```

### Run tests

```bash
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## License

MIT
