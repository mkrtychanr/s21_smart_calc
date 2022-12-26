CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TST_LIBS = -lcheck
ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit -lm
endif
LIB_NAME = s21_polish

SRCS=$(wildcard core/s21_*.c)

OBJS=$(SRCS:.c=.o)

all: clean tests

install: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) core/main.c -o graph
	rm -rf core/*.o

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc core/$(LIB_NAME).a $^
	ranlib core/$(LIB_NAME).a
	rm -rf core/*.o

linter:
	python3 ../cpplint.py --extensions=c *.c *.h tests/*.c tests/*.h

# check - либа для работы тестов, $(LIB_NAME) - наша либа
tests: clean $(LIB_NAME).a
	$(CC) $(FLAGS) core/check.c core/$(LIB_NAME).a $(TST_LIBS) -o core/tests
	./core/tests

main: $(LIB_NAME).a
	$(CC) $(FLAGS) main.c $(LIB_NAME).a $(TST_LIBS) -o Main

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag tests
	./core/tests
	rm -rf check*.gcda check*.gcno
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details
	rm -rf core/*.gcno core/*.gcda core/*.o
	mv *html ../reports/
	mv *css ../reports/
