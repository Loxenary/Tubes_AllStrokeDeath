.PHONY: all clean run

SRC_DIR = src
ADT_DIR = $(SRC_DIR)/adt
TEST_DIR = tests

MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ADT_SOURCES = $(wildcard $(ADT_DIR)/*.c)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)

run: main
	./main

main: main.o $(ADT_SOURCES) $(MAIN_SOURCES)
	gcc -Wall -std=c11 $^ -o $@

main.o: main.c
	gcc -Wall -std=c11 -c $< -o $@

test: Driver_AdjMatrix

Driver_AdjMatrix: $(TEST_DIR)/Driver_AdjMatrix.c $(ADT_SOURCES) $(MAIN_SOURCES)
	gcc -Wall -std=c11 $^ -o $@
	./$@

clean:
	rm -rf main main.o Driver_AdjMatrix
