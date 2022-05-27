CC = gcc
CFLAGS = -Wall -std=c99
INC = include
SRC = src
BIN = bin
TEST = test

all: setup cino test
	$(CC) $(CFLAGS) $(BIN)/*.o -o $(BIN)/test_cino

############### SETUP ###############

setup:
	mkdir -p $(BIN)

############### CINO ###############

cino: cino_utils cino_string cino_array cino_list cino_stack cino_queue cino_deque cino_tree cino_set cino_map

cino_utils: cino_utils_basic cino_utils_str cino_utils_wrapper

cino_utils_basic: $(SRC)/cino_utils_basic.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_utils_basic.c -o $(BIN)/cino_utils_basic.o

cino_utils_str: $(SRC)/cino_utils_str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_utils_str.c -o $(BIN)/cino_utils_str.o

cino_utils_wrapper: $(SRC)/cino_utils_wrapper.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_utils_wrapper.c -o $(BIN)/cino_utils_wrapper.o

cino_string: $(SRC)/cino_string.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_string.c -o $(BIN)/cino_string.o

cino_array: $(SRC)/cino_array.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_array.c -o $(BIN)/cino_array.o

cino_list: $(SRC)/cino_list.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_list.c -o $(BIN)/cino_list.o

cino_stack: $(SRC)/cino_stack.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_stack.c -o $(BIN)/cino_stack.o

cino_queue: $(SRC)/cino_queue.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_queue.c -o $(BIN)/cino_queue.o

cino_deque: $(SRC)/cino_deque.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_deque.c -o $(BIN)/cino_deque.o

cino_tree: $(SRC)/cino_tree.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_tree.c -o $(BIN)/cino_tree.o

cino_set: $(SRC)/cino_set.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_set.c -o $(BIN)/cino_set.o

cino_map: $(SRC)/cino_map.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/cino_map.c -o $(BIN)/cino_map.o

############### TEST ###############

test: test_cino_utils test_cino_string test_cino_array test_cino_list test_cino_stack test_cino_queue test_cino_deque test_cino_tree test_cino_set test_cino_map test_cino

test_cino_utils: $(TEST)/test_cino_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_utils.c -o $(BIN)/test_cino_utils.o

test_cino_string: $(TEST)/test_cino_string.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_string.c -o $(BIN)/test_cino_string.o

test_cino_array: $(TEST)/test_cino_array.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_array.c -o $(BIN)/test_cino_array.o

test_cino_list: $(TEST)/test_cino_list.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_list.c -o $(BIN)/test_cino_list.o

test_cino_stack: $(TEST)/test_cino_stack.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_stack.c -o $(BIN)/test_cino_stack.o

test_cino_queue: $(TEST)/test_cino_queue.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_queue.c -o $(BIN)/test_cino_queue.o

test_cino_deque: $(TEST)/test_cino_deque.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_deque.c -o $(BIN)/test_cino_deque.o

test_cino_tree: $(TEST)/test_cino_tree.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_tree.c -o $(BIN)/test_cino_tree.o

test_cino_set: $(TEST)/test_cino_set.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_set.c -o $(BIN)/test_cino_set.o

test_cino_map: $(TEST)/test_cino_map.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino_map.c -o $(BIN)/test_cino_map.o

test_cino: $(TEST)/test_cino.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_cino.c -o $(BIN)/test_cino.o

############### CLEAN ###############

clean:
	rm -rf $(BIN)
