CC = gcc
INCLUDE = ../src/

all: test test_iterator

test: ml_list.o ml_iterator_list.o test.c
	$(CC) -I$(INCLUDE) ml_list.o ml_iterator_list.o test.c -o test

test_iterator: ml_list.o ml_iterator_list.o
	$(CC) -I$(INCLUDE) ml_list.o ml_iterator_list.o test_iterator.c -o test_iterator

ml_list.o: ../src/ml_list.h ../src/ml_list.c ../src/ml_iterator_list.h ../src/ml_iterator_list.c
	$(CC) -c ../src/ml_list.h ../src/ml_list.c ../src/ml_iterator_list.h ../src/ml_iterator_list.c


ml_iterator_list.o: ../src/ml_list.h ../src/ml_list.c ../src/ml_iterator_list.h ../src/ml_iterator_list.c
	$(CC) -c ../src/ml_list.h ../src/ml_list.c ../src/ml_iterator_list.h ../src/ml_iterator_list.c

clean:
	rm -f *.o test test_iterator