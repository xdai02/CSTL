CC = gcc
CFLAGS = -Wall -std=c89
INC = include
SRC = src
BIN = bin
TEST = test

all: setup coop test
	$(CC) $(CFLAGS) $(BIN)/*.o -o $(BIN)/test_coop

############### SETUP ###############

setup:
	mkdir -p $(BIN)

############### COOP ###############

coop: str

str: $(SRC)/str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/str.c -o $(BIN)/str.o

############### TEST ###############

test: test_str test_coop

test_str: $(TEST)/test_str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_str.c -o $(BIN)/test_str.o

test_coop: $(TEST)/test_coop.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop.c -o $(BIN)/test_coop.o

############### CLEAN ###############

clean:
	rm -rf $(BIN)
