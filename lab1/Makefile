CC = gcc
CFLAGS = -std=c++17 -lstdc++ -pedantic -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) test_queue.cc -lgtest -o test
	./test

clean:
	rm -rf test