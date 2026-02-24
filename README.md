# LosslessSegmentationMapCompression

Lossless segmentation-map compression toolkit with two binaries:
- `encoder`: encodes input maps into a compressed bitstream
- `decoder`: decodes compressed bitstreams back to output maps

## 1. Prerequisites

Install a C++ compiler and build tools.

- macOS (Xcode Command Line Tools):
```bash
xcode-select --install
```

- Linux (example for Debian/Ubuntu):
```bash
sudo apt update
sudo apt install -y g++ make cmake
```

## 2. Get the Source

If you already have this repository locally, skip this section.

```bash
mkdir -p ~/workspace
cd ~/workspace
git clone <your-repo-url> losslesssegmentationmapcompression
cd losslesssegmentationmapcompression
```

## 3. Build (Option A: Makefile, simplest)

From the repository root:

```bash
make
```

This builds:
- `./encoder`
- `./decoder`

To clean artifacts:

```bash
make clean
```

## 4. Build (Option B: CMake out-of-source)

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -j
```

Binaries are generated in the build output directory.

## 5. Quick Run Examples

From the repository root (for Makefile build):

### Encode
```bash
./encoder -i input.yuv -o output.bin -r 1024 -c 2048 -f 1 -s 0 -t 400
```

### Decode
```bash
./decoder -i output.bin -o recover.yuv
```

## 6. Command Arguments

### Encoder (`./encoder`)
- `-i`: input file (`.yuv`)
- `-o`: output bitstream file
- `-r`: rows
- `-c`: cols
- `-f`: frame count
- `-s`: skip frame count
- `-t`: type (`400` or `420`)

### Decoder (`./decoder`)
- `-i`: encoded input file (`.bin`)
- `-o`: reconstructed output file (`.yuv`)

## 7. Project Layout

```text
source/
  commonlib/
  third_party/
  encoder/
  decoder/
Makefile
CMakeLists.txt
```

## 8. Notes

- The codebase currently compiles with warnings on strict flags; binaries are still produced.
- If `cmake` is unavailable, use the Makefile flow (`make`).
