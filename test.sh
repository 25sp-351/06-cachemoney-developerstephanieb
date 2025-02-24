#!/bin/bash

echo "Compiling program..."
make > /dev/null 2>&1

if [ ! -f "./money_to_text" ]; then
    echo "❌ Compilation failed. Exiting."
    exit 1
fi

echo "✅ Compilation successful."

TEST_CASES=(
    "0"
    "101"
    "122309"
    "149999"
    "150000"
    "-5"
    "99999999"
    "hello"
    "12.34"
    ""
)

EXPECTED_OUTPUTS=(
    "Text for 0 cents: 0 dollars and 0 cents"
    "Text for 101 cents: 1 dollar and 1 cent"
    "Text for 122309 cents: 1223 dollars and 9 cents"
    "Text for 149999 cents: 1499 dollars and 99 cents"
    "Text for 150000 cents: 1500 dollars and 0 cents"
    "Amount cannot be negative: -5"
    "Text for 99999999 cents: 999999 dollars and 99 cents"
    "Invalid integer input: hello"
    "Invalid integer input: 12.34"
    "Usage: ./money_to_text <amount_in_cents>"
)

echo "Running tests..."
for i in "${!TEST_CASES[@]}"; do
    INPUT="${TEST_CASES[$i]}"
    EXPECTED="${EXPECTED_OUTPUTS[$i]}"

    # If input is empty, we invoke the program with no arguments.
    if [ -z "$INPUT" ]; then
        OUTPUT=$(./money_to_text 2>&1)
    else
        OUTPUT=$(./money_to_text "$INPUT" 2>&1)
    fi

    if [[ "$OUTPUT" == *"$EXPECTED"* ]]; then
        echo "✅ Test Passed: Input '$INPUT'"
    else
        echo "❌ Test Failed: Input '$INPUT'"
        echo "   Expected: '$EXPECTED'"
        echo "   Got:      '$OUTPUT'"
    fi
done

echo "Cleaning up..."
make clean > /dev/null 2>&1
echo "✅ Tests complete."