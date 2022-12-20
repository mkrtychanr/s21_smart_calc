CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: recreate_build_dir gui core

core:
	@cd src/ && make && mv graph ../build/graph

gui:
	@cd build/ && qmake ../src/gui/Calculator.pro && make && mv Calculator.app/Contents/MacOs/Calculator ../Calculator
	rm -rf build/*
	rm -rf build/.qmake.stash
	mv Calculator build/Calculator

recreate_build_dir:
	@rm -rf build
	@mkdir build