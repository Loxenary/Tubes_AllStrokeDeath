.PHONY: all clean run
.DEFAULT_GOAL := all
SRC_DIR = src
ADT_DIR = $(SRC_DIR)/adt
TEST_DIR = tester
BUILD_DIR = build

MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ADT_SOURCES = $(wildcard $(ADT_DIR)/*.c)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)

MAIN_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(MAIN_SOURCES))
ADT_OBJ = $(patsubst $(ADT_DIR)/%.c,$(BUILD_DIR)/%.o, $(ADT_SOURCES)) 
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SOURCES))

all: main
	valgrind  --leak-check=full ./main

CC = gcc
CFLAGS = -Wall -std=c11

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ADT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

main_obj = $(BUILD_DIR)/main.o

main: $(main_obj) $(MAIN_OBJ) $(ADT_OBJ)
	 gcc -g -Wall -std=c11 $^ -o $@

# Test File

TEST_BINARIES = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%,$(TEST_SOURCES:.c=.o	 ))

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/test_%.c
	@echo "Compiling $< into $@ with dependencies: $(ADT_OBJ)"
	$(CC) $(CFLAGS) -c $< -o $@ $(ADT_OBJ) I$(ADT_OBJ)

run_tests: $(TEST_BINARIES)
	@echo "TEST_BINARIES: $(TEST_BINARIES)"
	@for test_binary in $(TEST_BINARIES); do \
		echo "Running test: $$test_binary"; \
		./$${test_binary}; \
   	done

# # Adjoin Matriks
# $(BUILD_DIR)/Driver_AdjMatrix.o: $(TEST_DIR)/Driver_AdjMatrix.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# $(BUILD_DIR)/Driver_ListStatikWord.o: $(TEST_DIR)/Driver_ListStatikWord.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# $(BUILD_DIR)/Driver_ListUtas.o: $(TEST_DIR)/Driver_ListUtas.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# adjoin_obj = $(BUILD_DIR)/Driver_AdjMatrix.o

# # ListStatikWord
# Driver_AdjMatrix: $(adjoin_obj) $(MAIN_OBJ) $(ADT_OBJ)
# 	gcc -Wall -std=c11 $^ -o $@

# Driver_ListUtas: $()
# list_statik_word_obj = $(BUILD_DIR)/Driver_ListStatikWord.o

# test: Driver_AdjMatrix Driver_ListStatikWord Driver_ListUtas
# 	#./Driver_ListUtas
# 	./Driver_AdjMatrix
# 	./Driver_ListStatikWord
# # ListUtas
# list_utas_obj = $(BUILD_DIR)/Driver_ListUtas.o

# Driver_AdjMatrix: $(adjoin_obj) $(MAIN_OBJ) $(ADT_OBJ)
# 	gcc -g -Wall -std=c11 $^ -o $@

# Driver_ListStatikWord: $(list_statik_word_obj) $(MAIN_OBJ) $(ADT_OBJ)
# 	gcc -Wall -std=c11 $^ -o $@

# Driver_ListUtas: $(list_utas_obj) $(MAIN_OBJ) $(ADT_OBJ)
# 	gcc -Wall -std=c11 $^ -o $@
clean:
	rm -rf $(BUILD_DIR)/*.o main Driver_AdjMatrix Driver_ListStatikWord
