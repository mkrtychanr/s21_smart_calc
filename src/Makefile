CC = gcc
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) core/graph.c core/stack.c core/double_stack.c core/parse.c core/calculate.c -o graph
clean:
	rm -rf ../build/graph ../build/*.txt

rebuild: clean all