# C Calculator

Console calculator in C by Harsh Verma.

## Features
- Add, subtract, multiply, divide
- Modulus for integers, power (a^b), square root, factorial
- Input validation, divide-by-zero / invalid-input guards
- Menu loop, clean functions (one function per operation)

## Build
```bash
gcc calculator.c -o calculator -lm
# Windows (MinGW, -lm optional)
gcc calculator.c -o calculator.exe
```

## Run
```bash
./calculator
# Windows
calculator.exe
```

## Example
```
==== C Calculator ====
1. Add (+)
2. Subtract (-)
3. Multiply (*)
4. Divide (/)
5. Modulus (%, integers)
6. Power (a ^ b)
7. Square root
8. Factorial (n!)
9. Exit
Enter choice (1-9): 1
Enter first number: 12
Enter second number: 8
Result: 20.00
```

## Live demo
- Standalone: https://harsh17908.github.io/c-calculator/
- In portfolio: https://harsh17908.github.io/personal-portfolio/#projects
- `demo.html` / `index.html` — same logic in the browser

Author: https://github.com/harsh17908
