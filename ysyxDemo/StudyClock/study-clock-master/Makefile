CC := cc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude -D _DEFAULT_SOURCE

SRC_DIR := csrc
BUILD_DIR := build

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := $(BUILD_DIR)/study-clock

.PHONY: all clean run fancy

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

fancy: $(TARGET)
	./$(TARGET) --fancy

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
