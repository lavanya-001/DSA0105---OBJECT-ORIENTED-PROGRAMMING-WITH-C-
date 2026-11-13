TASK 02 – COPY CONSTRUCTORS: SHALLOW AND DEEP COPY

Name: Lavanya K.
Register Number: 192565025
Language: C++
Compiler: G++ 15.2.0

PROGRAMS:
1. shallow_copy.cpp – Demonstrates shallow copying.
2. deep_copy.cpp – Implements deep copy constructor.
3. copy_count.cpp – Counts copies using value and reference.

CONCEPTS:
- Shallow copy and shared memory.
- Deep copy using dynamic memory allocation.
- Copy constructor.
- Copy assignment operator.
- Destructor.
- Self-assignment protection.
- Rule of Three.
- AddressSanitizer memory checking.

RESULT:
Shallow copy produced a memory error.
Deep copy worked correctly without memory errors.
Copy assignment and self-assignment were tested.
Passing by reference avoided unnecessary copying.

COMPILE COMMAND:
g++ -std=c++17 -fsanitize=address -g deep_copy.cpp -o deep_copy

RUN COMMAND:
./deep_copy
