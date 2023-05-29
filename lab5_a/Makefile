CC = g++
CFLAGS = -Wall -Wextra -Werror
TESTLIB = -lgtest

SRC = $(wildcard *.cc)

test:
	$(CC) $(CFLAGS) $(SRC) $(TESTLIB) -o test_graph
	./test_graph

clean:
	rm test_graph

style:
	clang-format -style=Google -i *.cc *.h