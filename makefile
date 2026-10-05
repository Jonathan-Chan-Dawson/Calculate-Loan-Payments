CC = g++

all: main.out

main.out: main.cpp
	$(CC) -std=c++11 main.cpp -o main.out

tests: main.out
	bash tests.sh

clean:
	rm -f *.o *.out tests

.PHONY: all tests clean
