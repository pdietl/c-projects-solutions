BUILD_DIR  := build
BIN_OUTPUT := $(BUILD_DIR)/main


.PHONY: all
all: $(BIN_OUTPUT)

$(BUILD_DIR):
	meson $@

$(BIN_OUTPUT): | $(BUILD_DIR)
	meson compile -C $(@D)

.PHONY: clean
clean:
	meson compile --clean -C $(BUILD_DIR)
