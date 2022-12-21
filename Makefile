CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: delete_temp_build recreate_build_dir gui core

core:
	@cd src/ && make && mv graph ../build/graph

gui:
	@mkdir .temp_build
	@cd .temp_build/ && qmake ../src/gui/Calculator.pro && make && mv Calculator.app/Contents/MacOs/Calculator ../build/Calculator
	rm -rf .temp_build

delete_temp_build:
	rm -rf .temp_build

recreate_build_dir:
	@rm -rf build
	@mkdir build