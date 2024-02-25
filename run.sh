#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <input_file> <cpp_program>"
    exit 1
fi

input_file="$1"
cpp_program="$2"

if [ ! -f "$input_file" ]; then
    echo "Error: Input file '$input_file' not found"
    exit 1
fi

if [ ! -x "$cpp_program" ]; then
    echo "Error: C++ program '$cpp_program' not found or not executable"
    exit 1
fi

while IFS= read -r line; do
    input1=$(echo "$line" | awk '{print $1}')
    input2=$(echo "$line" | awk '{print $2}')
    expected_output=$(echo "$line" | awk '{print $3}')
    actual_output=$(echo "$input1 $input2" | "$cpp_program")
    echo "$input1 $input2 $actual_output $expected_output"
done < "$input_file"
