.PHONY: all run_cpp_msvc debug_leak_drmemory run_cpp_gcc debug_leak_valgrind clean

all: run_cpp debug_leak_drmemory run_cpp_gcc debug_leak_valgrind

run_cpp_msvc:
	cd cpp
	cl.exe /O2 /EHsc /W4 /std:c++17 test.cpp /Fe:test_cpp.exe
	test_cpp.exe

run_cpp_gcc:
	cd cpp
	g++ -O3 -Wall -Wextra -std=c++17 test.cpp -o test_cpp
	./test_cpp

debug_leak_drmemory:
	cd cpp
	cl.exe /Zi /Od /EHsc /MDd /W4 /std:c++17 test.cpp /Fe:test_cpp.exe
	drmemory.exe -- test_cpp.exe

debug_leak_valgrind:
	cd cpp
	g++ -g -O0 -Wall -Wextra -std=c++17 test.cpp -o test_cpp
	valgrind --leak-check=full ./test_cpp


clean:
	@for /R cpp %%F in (*) do ( \
		if /I not "%%~nxF"=="test.cpp" del "%%F" \
	)