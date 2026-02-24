CXX ?= g++

CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra
CPPFLAGS ?= -Isource/commonlib -Isource/third_party -Isource/encoder -Isource/decoder

BUILD_DIR := build

COMMON_SRCS := \
	source/commonlib/coding_unit.cpp \
	source/commonlib/global_arithmetic.cpp \
	source/commonlib/utility.cpp \
	source/third_party/arithmetic_codec.cpp

ENCODER_SRCS := source/encoder/encoder.cpp source/encoder/encOptions.cpp
DECODER_SRCS := source/decoder/decoder.cpp source/decoder/decOptions.cpp

COMMON_OBJS := $(COMMON_SRCS:%=$(BUILD_DIR)/%.o)
ENCODER_OBJS := $(ENCODER_SRCS:%=$(BUILD_DIR)/%.o)
DECODER_OBJS := $(DECODER_SRCS:%=$(BUILD_DIR)/%.o)

.PHONY: all clean

all: encoder decoder

encoder: $(COMMON_OBJS) $(ENCODER_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

decoder: $(COMMON_OBJS) $(DECODER_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) encoder decoder
