# Task 03 - Performance Comparison

## Objective
To compare virtual functions with switch-case and exception handling with return codes.

## Experiments
1. Tested 10, 1,000, 1,000,000 and 10,000,000 bills.
2. Compared virtual function and switch-case execution time.
3. Compared exceptions and return codes at 0%, 1% and 50% invalid inputs.

## Compile
g++ -std=c++17 -O2 -Wall -Wextra benchmark.cpp -o benchmark

## Run
./benchmark

## Result
Virtual function dispatch took more time than switch-case in the tested program.

Exceptions performed well when no errors occurred but became slower when invalid inputs increased.

Return codes were more efficient when errors occurred frequently.

## Conclusion
Runtime polymorphism improves extensibility and maintainability. Switch-case may be faster in this benchmark. Exceptions should be used for exceptional conditions, while return codes are suitable for frequent validation failures.
