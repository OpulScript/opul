export VERSION=0.0.1 # Opul version

CONFIG=config/mk/default.mk
include $(CONFIG)

SOURCES_C=$(wildcard src/*.c)
OBJECTS_C=$(patsubst src/%.c, $(BUILD_DIR)/obj/%.obj, $(SOURCES_C))

all: opul

opul: build_dirs $(BUILD_DIR)/opul

$(BUILD_DIR)/opul: $(OBJECTS_C)
	@$(LD) $^ -o $@
	@echo "--> Linked" $(notdir $@)

$(BUILD_DIR)/obj/%.obj: src/%.c
	@$(CC) -c $^ -o $@
	@echo "--> Compiled" $^

build_dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/obj

clean:
	@rm -f -r build/*
	@echo "--> Cleaned output"

.PHONY: all opul clean build_dirs