.PHONY: all run_cpp debug_leak_drmemory debug_leak_valgrind clean

all: run_cpp debug_leak_drmemory debug_leak_valgrind

run_cpp:
	g++ -O3 -Wall -Wextra test.cpp -o test
	./test

debug_leak_drmemory:
	g++ -g -O0 -Wall -Wextra test.cpp -o test.exe
	drmemory.exe -- test.exe

debug_leak_valgrind:
	g++ -g -O0 -Wall -Wextra test.cpp -o test
	valgrind --leak-check=full ./test

clean:
	del test.exe
