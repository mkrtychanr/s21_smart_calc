CC = gcc
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) graph.c stack.c double_stack.c parse.c calculate.c -o ../build/graph
polish:
	$(CC) $(CFLAGS) core/graph.c core/stack.c core/double_stack.c core/parse.c core/calculate.c -o ../build/graph
clean:
	rm -rf ../build/graph ../build/*.txt

rebuild: clean all