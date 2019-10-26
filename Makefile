FLAGS=-std=c++11 -I.

.PHONY: all main test run-test

all: main test

main: out/run

test: out/test

out/run: out/main.o out/BraceChecker.o
	g++  ${FLAGS} $^ -o $@

out/test: out/test.o out/BraceChecker.o
	g++ ${FLAGS} $^ -o $@

out/BraceChecker.o: BraceChecker.cpp BraceChecker.h
	g++ ${FLAGS} -c $< -o $@

out/main.o: main.cpp *.h
	g++ ${FLAGS} -c $< -o $@

out/test.o: test/test.cpp test/*.hh *.h
	g++ ${FLAGS} -c $< -o $@

run: out/run
	./$<

run-test: out/test
	./$<
