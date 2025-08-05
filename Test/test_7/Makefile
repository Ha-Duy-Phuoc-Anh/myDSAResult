.PHONY: all run_c debug_leak_drmemory debug_leak_valgrind clean

all: run_c debug_leak_drmemory debug_leak_valgrind

run_c:
	gcc -O3 -Wall -Wextra test.c -o test
	./test

debug_leak_drmemory:
	gcc -g -O0 -Wall -Wextra test.c -o test.exe
	drmemory.exe -- test.exe

debug_leak_valgrind:
	gcc -g -O0 -Wall -Wextra test.c -o test
	valgrind --leak-check=full ./test

clean:
	del test.exe
