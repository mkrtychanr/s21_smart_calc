CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: uninstall install gcov_report dvi dist

install: delete_temp_build recreate_build_dir gui core

uninstall: 
	@rm -rf build

core:
	@cd src/ && make install && mv graph ../build/graph

tests:
	@cd src/ && make tests

gcov_report:
	rm -rf reports
	mkdir reports
	@cd src/ && make gcov_report
	open reports/gcov_report.html

gui:
	@mkdir .temp_build
	@cd .temp_build/ && qmake ../src/gui/Calculator.pro && make && mv Calculator.app/Contents/MacOs/Calculator ../build/Calculator
	rm -rf .temp_build

dvi:
	@doxygen conf && mv html documentation
	@open documentation/index.html

dist:
	@rm -rf dist.tar.gz
	@tar -cvzf dist.tar.gz build/Calculator build/graph

delete_temp_build:
	rm -rf .temp_build

recreate_build_dir:
	@rm -rf build
	@mkdir build

clean:
	rm -rf reports/*