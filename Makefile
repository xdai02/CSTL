CC = gcc
CFLAGS = -Wall -std=c99
INC = ./include/
SRC = ./src/
BIN = ./bin/
TEST = ./test/

# Create bin directory
$(shell mkdir -p $(BIN))

############### CINO ###############

all: cino_utils cino_string cino
	$(CC) $(CFLAGS) $(BIN)cino_utils.o $(BIN)cino_string.o $(BIN)cino.o -o $(BIN)cino

cino_utils: $(SRC)cino_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)cino_utils.c -o $(BIN)cino_utils.o

cino_string: $(SRC)cino_string.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)cino_string.c -o $(BIN)cino_string.o

cino: $(SRC)cino.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)cino.c -o $(BIN)cino.o

############### TEST ###############

test: test_cino_utils test_cino_string test_cino
	$(CC) $(CFLAGS) $(BIN)cino_utils.o $(BIN)cino_string.o $(BIN)test_cino_utils.o $(BIN)test_cino_string.o $(BIN)test_cino.o -o $(BIN)test_cino

test_cino_utils: cino_utils $(TEST)test_cino_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)test_cino_utils.c -o $(BIN)test_cino_utils.o

test_cino_string: cino_string $(TEST)test_cino_string.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)test_cino_string.c -o $(BIN)test_cino_string.o

test_cino: $(TEST)test_cino.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)test_cino.c -o $(BIN)test_cino.o

############### CLEAN ###############

.PHONY: clean
clean:
	rm -rf $(BIN)