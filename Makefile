CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: 

gui:
	@cd build/ && qmake ../src/gui/Calculator.pro && make && mv Calculator.app/Contents/MacOs/Calculator ../Calculator
	rm -rf build/*
	rm -rf build/.qmake.stash
	mv Calculator build/Calculator
delete_build_dir:
	@rm -rf build

create_build_dir:
	@mkdir build