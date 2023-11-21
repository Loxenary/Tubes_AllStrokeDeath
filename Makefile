.PHONY: all clean run
.DEFAULT_GOAL := all
SRC_DIR = src
ADT_DIR = $(SRC_DIR)/adt
TEST_DIR = Tester
BUILD_DIR = build

MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ADT_SOURCES = $(wildcard $(ADT_DIR)/*.c)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)

MAIN_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(MAIN_SOURCES))
ADT_OBJ = $(patsubst $(ADT_DIR)/%.c,$(BUILD_DIR)/%.o, $(ADT_SOURCES)) 
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SOURCES))

all: main
	./main

CC = gcc
CFLAGS = -Wall -std=c11

all: $(BUILD_DIR) main
	valgrind --leak-check=full ./main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ADT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

main_obj = $(BUILD_DIR)/main.o

main: $(main_obj) $(MAIN_OBJ) $(ADT_OBJ)
	 gcc -Wall -std=c11 $^ -o $@

# Adjoin Matriks
$(BUILD_DIR)/Driver_AdjMatrix.o: $(TEST_DIR)/Driver_AdjMatrix.c
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/Driver_ListStatikWord.o: $(TEST_DIR)/Driver_ListStatikWord.c
	$(CC) $(CFLAGS) -c $< -o $@

adjoin_obj = $(BUILD_DIR)/Driver_AdjMatrix.o

# ListStatikWord
Driver_AdjMatrix: $(adjoin_obj) $(MAIN_OBJ) $(ADT_OBJ)
	gcc -Wall -std=c11 $^ -o $@
list_statik_word_obj = $(BUILD_DIR)/Driver_ListStatikWord.o

test: Driver_AdjMatrix Driver_ListStatikWord
	./Driver_AdjMatrix
	valgrind ./Driver_ListStatikWord -s --leak-check=full

Driver_AdjMatrix: $(adjoin_obj) $(MAIN_OBJ) $(ADT_OBJ)
	gcc -Wall -std=c11 $^ -o $@

Driver_ListStatikWord: $(list_statik_word_obj) $(MAIN_OBJ) $(ADT_OBJ)
	gcc -Wall -std=c11 $^ -o $@
clean:
	rm -rf $(BUILD_DIR)/*.o main Driver_AdjMatrix Driver_ListStatikWord
