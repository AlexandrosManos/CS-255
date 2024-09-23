###################################################
#
# file: Makefile
#
# @Author:   Iacovos G. Kolokasis
# @Version:  10-02-2022
# @email:    kolokasis@csd.uoc.gr
#
# Makefile
#
####################################################

all: list.exe hash.exe

CC = gcc
CFLAGS = -Wall -ansi -pedantic

list.exe: src/main.o src/symtablelist.o
	$(CC) $(CFLAGS) $^ -o $@

hash.exe: src/main.o src/symtablehash.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	-rm -f *.exe ./src/*.o