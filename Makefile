CC = gcc
CFLAGS = -Wall -std=c99

all: cino_utils.o cino_string.o cino.o
	$(CC) $(CFLAGS) cino_utils.o cino_string.o cino.o -o cino

cino.o: cino.c
	$(CC) $(CFLAGS) -c cino.c

cino_utils.o: cino_utils.c
	$(CC) $(CFLAGS) -c cino_utils.c

cino_string.o: cino_string.c
	$(CC) $(CFLAGS) -c cino_string.c

clean:
	rm -rf *.o *.exe cino