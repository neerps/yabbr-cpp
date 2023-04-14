CXX=/usr/bin/g++

BUILD_DIR ?= ./build
SRC_DIR ?= ./src
INC_DIR ?= ./include
EXEC_NAME ?= raytracing_one
DEBUG_FLAGS ?= -o2 -DNDEBUG

SRCS := $(shell find "$(SRC_DIR)" -name '*.cpp')

INC_FLAGS := $(addprefix -I,$(INC_DIR))
CPPFLAGS := $(INC_FLAGS)
CXXFLAGS := $(DEBUG_FLAGS)\
	-pedantic-errors\
	-Wall -Weffc++\
	-Wextra\
	-Wsign-conversion\
	-Werror

.DELETE_ON_ERROR:
default: $(BUILD_DIR)/$(EXEC_NAME)
$(BUILD_DIR)/$(EXEC_NAME):
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
