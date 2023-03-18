CXX=/usr/bin/g++
EXEC_NAME := raytracing_one

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find "$(SRC_DIRS)" -name '*.cpp')
INC_DIRS := $(shell find "$(SRC_DIRS)" -type d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS)
CXXFLAGS := -o2\
	-pedantic-errors\
	-Wall -Weffc++\
	-Wextra\
	-Wsign-conversion\
	-Werror

default: $(BUILD_DIR)/$(EXEC_NAME)
$(BUILD_DIR)/$(EXEC_NAME):
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
