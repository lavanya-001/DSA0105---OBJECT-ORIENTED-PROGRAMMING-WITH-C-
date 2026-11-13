# Task 04 - Final Engineering Decision

## Objective
To build an extensible hospital billing system using runtime polymorphism, abstract classes, exception handling and smart pointers.

## Implemented Features
1. Abstract Bill class.
2. OutPatient and InPatient derived classes.
3. New EmergencyBill class.
4. Abstract Payer class.
5. SelfPay and Insurance payment classes.
6. New CorporatePayer class.
7. Exception handling for invalid bill amounts.
8. unique_ptr for automatic memory management.

## Compile
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g final_system.cpp -o final_system

## Run
./final_system

## Result
The billing system successfully processed outpatient, inpatient and emergency bills. Runtime polymorphism selected the correct billing and payment methods. Smart pointers automatically destroyed all bill objects.

AddressSanitizer reported no errors.

## Engineering Decision
Runtime polymorphism is suitable for extending the billing system with new bill and payer types. Smart pointers provide automatic memory management. Exceptions are suitable for exceptional errors, while return codes may be more efficient for frequent validation failures.
