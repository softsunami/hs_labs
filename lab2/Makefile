CC = g++
CFLAGS = -Wall -Wextra -Werror
TESTLIB = -lgtest

test:
	$(CC) $(CFLAGS) test.cc $(TESTLIB) -o test_map
	./test_map

clean:
	rm test_map