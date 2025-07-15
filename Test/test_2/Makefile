.PHONY: all run_py run_cpp debug_leak clean

all: run_py run_cpp debug_leak

run_py:
	python test.py

run_cpp:
	cd cpp
	cl.exe /O2 /EHsc /W4 /std:c++23preview test.cpp /Fe:test_cpp.exe
	test_cpp.exe


debug_leak:
	cd cpp
	cl.exe /Zi /Od /EHsc /MDd /W4 /std:c++23preview test.cpp /Fe:test_cpp.exe
	drmemory.exe -- test_cpp.exe

clean:
	@for /R cpp %%F in (*) do ( \
		if /I not "%%~nxF"=="test.cpp" del "%%F" \
	)