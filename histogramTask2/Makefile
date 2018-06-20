CC=musl-gcc

FLAGS=-g -O3 -lm

all: histogram child

histogram: histogram.c struct.h
	$(CC) $(FLAGS) histogram.c -o histogram
child: child.c struct.h
	$(CC) $(FLAGS) child.c -o child
clean:
	rm histogram
