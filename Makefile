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

coop: coop_utils coop_wrapper coop_str

coop_utils: $(SRC)/coop_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/coop_utils.c -o $(BIN)/coop_utils.o

coop_wrapper: $(SRC)/coop_wrapper.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/coop_wrapper.c -o $(BIN)/coop_wrapper.o

coop_str: $(SRC)/coop_str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(SRC)/coop_str.c -o $(BIN)/coop_str.o

############### TEST ###############

test: test_coop_utils test_coop_str test_coop

test_coop_utils: $(TEST)/test_coop_utils.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop_utils.c -o $(BIN)/test_coop_utils.o

test_coop_str: $(TEST)/test_coop_str.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop_str.c -o $(BIN)/test_coop_str.o

test_coop: $(TEST)/test_coop.c
	$(CC) $(CFLAGS) -I$(INC) -c $(TEST)/test_coop.c -o $(BIN)/test_coop.o

############### CLEAN ###############

clean:
	rm -rf $(BIN)
