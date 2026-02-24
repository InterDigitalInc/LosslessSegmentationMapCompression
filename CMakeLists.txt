cmake_minimum_required(VERSION 3.16)

project(LosslessSegmentationMapCompression LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMON_SOURCES
    source/commonlib/coding_unit.cpp
    source/commonlib/global_arithmetic.cpp
    source/commonlib/utility.cpp
    source/third_party/arithmetic_codec.cpp
)

add_library(commonlib STATIC ${COMMON_SOURCES})
target_include_directories(
    commonlib
    PUBLIC
      source/commonlib
      source/third_party
)

add_executable(
    encoder
    source/encoder/encoder.cpp
    source/encoder/encOptions.cpp
)
target_link_libraries(encoder PRIVATE commonlib)
target_include_directories(
    encoder
    PRIVATE
      source/commonlib
      source/third_party
      source/encoder
)

add_executable(
    decoder
    source/decoder/decoder.cpp
    source/decoder/decOptions.cpp
)
target_link_libraries(decoder PRIVATE commonlib)
target_include_directories(
    decoder
    PRIVATE
      source/commonlib
      source/third_party
      source/decoder
)
