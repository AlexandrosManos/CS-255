

all: data3 data6 data9 data10

CC = gcc
CFLAGS = -Wall -ansi -pedantic

data3:
	$(CC) $(CFLAGS) src/create$@.c -o src/$@.out
data6:
	$(CC) $(CFLAGS) src/create$@.c -o src/$@.out
data9:
	$(CC) $(CFLAGS) src/create$@.c -o src/$@.out
data10:
	$(CC) $(CFLAGS) src/create$@.c -o src/$@.out
clean:
	-rm -f ./src/*.out
	-rm -f ./src/data*

