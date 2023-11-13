CC = gcc
CFLAGS = -Wall -Iinclude

SRC_DIR = src/adt
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(BIN_DIR)/myprogram

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: all clean
