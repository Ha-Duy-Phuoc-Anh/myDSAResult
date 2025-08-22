#!/bin/bash
set -e

# Kiểm tra tham số
if [ -z "$1" ]; then
    echo "Usage: $0 [test_<number>] [/debug|/release]"
    exit 1
fi

TEST_FOLDER="$1"
BUILD_MODE="$2"   # /debug hoặc /release

TEST_FILE="test.cpp"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEST_PATH_FULL="$SCRIPT_DIR/$TEST_FOLDER/$TEST_FILE"
TEST_OUTPUT="$SCRIPT_DIR/build/$TEST_FOLDER/test"

# Tạo thư mục source nếu chưa có
mkdir -p "$SCRIPT_DIR/$TEST_FOLDER"

# Tạo file test.cpp nếu chưa có
if [ ! -f "$TEST_PATH_FULL" ]; then
    echo "// Auto-generated empty test.cpp" > "$TEST_PATH_FULL"
fi

# Tạo thư mục build/<TEST_FOLDER>
mkdir -p "$SCRIPT_DIR/build/$TEST_FOLDER"

# Compile
echo "Compiling $TEST_FILE in $TEST_FOLDER ($BUILD_MODE)..."
if [ "$BUILD_MODE" == "/debug" ]; then
    g++ -g -O0 "$TEST_PATH_FULL" -o "$TEST_OUTPUT"
else
    g++ -O2 "$TEST_PATH_FULL" -o "$TEST_OUTPUT"
fi

# Run
echo "Running program..."
if [ "$BUILD_MODE" == "/debug" ]; then
    valgrind --leak-check=full "$TEST_OUTPUT"
else
    "$TEST_OUTPUT"
fi

