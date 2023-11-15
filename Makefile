# CC = gcc
# CFLAGS = -Wall -Werror -std=c11

# SRC_DIR = src
# BUILD_DIR = build
# BIN_DIR = bin
# TARGET = $(BIN_DIR)/birbir

# MAIN_FILE = main.c
# MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
# ADTSOURCE = $(wildcard $(SRC_DIR)/adt/*.c)

# MAIN_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(MAIN_SOURCES))
# ADT_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(ADTSOURCE))

# all: $(TARGET)

# $(TARGET): $(ADT_OBJECTS) $(MAIN_OBJECTS)
# 	$(CC) $(CFLAGS) -o $@ $^

# $(BUILD_DIR)/%.o: $(SRC_DIR)/adt/%.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# $(BUILD_DIR)/main.o: $(MAIN_FILE)
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# .PHONY: all clean

# clean:
# 	rm -rf $(BUILD_DIR)/*.o $(TARGET)

SRC_DIR = src
ADT_DIR = $(SRC_DIR)/adt

MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ADT_SOURCES = $(wildcard $(ADT_DIR)/*.c) 


run: 
	gcc $(ADT_SOURCES) $(MAIN_SOURCES) main.c -o main 
		./main