.PHONY: test

CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -Werror
SRC_FILES = $(wildcard *.cc)

test:
	$(CC) $(CFLAGS) $(SRC_FILES) -lgtest -o test
	./test

clean:
	rm -rf test