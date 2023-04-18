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

coop: coop_utils wrapper str

coop_utils: $(SRC)/coop_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/coop_utils.c -o $(BIN)/coop_utils.o

wrapper: $(SRC)/wrapper.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/wrapper.c -o $(BIN)/wrapper.o

str: $(SRC)/str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/str.c -o $(BIN)/str.o

############### TEST ###############

test: test_coop_utils test_str test_coop

test_coop_utils: $(TEST)/test_coop_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop_utils.c -o $(BIN)/test_coop_utils.o

test_str: $(TEST)/test_str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_str.c -o $(BIN)/test_str.o

test_coop: $(TEST)/test_coop.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop.c -o $(BIN)/test_coop.o

############### CLEAN ###############

clean:
	rm -rf $(BIN)
