CC = gcc
INCLUDE = ../src/

all: test

test: ml_list.o test.c
	$(CC) -I$(INCLUDE) ml_list.o test.c -o test

ml_list.o: ../src/ml_list.h ../src/ml_list.c
	$(CC) -c ../src/ml_list.h ../src/ml_list.c

clean:
	rm -f *.o test