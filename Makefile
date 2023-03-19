CXX=/usr/bin/g++

BUILD_DIR ?= ./build
SRC_DIR ?= ./src
EXEC_NAME ?= raytracing_one

SRCS := $(shell find "$(SRC_DIR)" -name '*.cpp')
INC_DIRS := $(shell find "$(SRC_DIR)" -type d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS)
CXXFLAGS := -o2\
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
