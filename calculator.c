/*
 * Calculator - console utility in C
 * Author: Harsh Verma (github.com/harsh17908)
 * Features: add, subtract, multiply, divide, modulus,
 *           power, square root, factorial
 * Build: gcc calculator.c -o calculator -lm
 *        (on Windows MinGW, -lm is optional: gcc calculator.c -o calculator.exe)
 * Run: ./calculator  (Windows: calculator.exe)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Discard leftover input up to newline, so next scanf starts clean. */
static void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* Prompt and read a double. Returns 1 on success, 0 on bad input. */
static int read_double(const char *prompt, double *out) {
    printf("%s", prompt);
    if (scanf("%lf", out) != 1) {
        printf("Invalid number. Try again.\n");
        clear_stdin();
        return 0;
    }
    clear_stdin();
    return 1;
}

/* Prompt and read an int menu choice. Returns 1 on success, 0 on bad input. */
static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        printf("Invalid choice. Enter a number 1-9.\n");
        clear_stdin();
        return 0;
    }
    clear_stdin();
    return 1;
}

/* --- Operations (one function each, easy to test/reuse) --- */
static double add(double a, double b)      { return a + b; }
static double subtract(double a, double b) { return a - b; }
static double multiply(double a, double b) { return a * b; }

/* Returns 1 and sets *result on success, 0 on divide-by-zero. */
static int divide(double a, double b, double *result) {
    if (b == 0.0) return 0;
    *result = a / b;
    return 1;
}

/* Returns 1 and sets *result on success, 0 if b == 0. */
static int modulus(long a, long b, long *result) {
    if (b == 0) return 0;
    *result = a % b;
    return 1;
}

static double power(double base, double exp) { return pow(base, exp); }

/* Returns 1 and sets *result on success, 0 if x < 0. */
static int square_root(double x, double *result) {
    if (x < 0.0) return 0;
    *result = sqrt(x);
    return 1;
}

/* Returns 1 and sets *result on success, 0 if n < 0. */
static int factorial(int n, long long *result) {
    if (n < 0) return 0;
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    *result = f;
    return 1;
}

static void print_menu(void) {
    printf("\n==== C Calculator ====\n");
    printf("1. Add (+)\n");
    printf("2. Subtract (-)\n");
    printf("3. Multiply (*)\n");
    printf("4. Divide (/)\n");
    printf("5. Modulus (%%, integers)\n");
    printf("6. Power (a ^ b)\n");
    printf("7. Square root\n");
    printf("8. Factorial (n!)\n");
    printf("9. Exit\n");
}

int main(void) {
    int choice = 0;

    while (1) {
        print_menu();
        if (!read_int("Enter choice (1-9): ", &choice)) continue;

        if (choice == 9) {
            printf("Goodbye.\n");
            break;
        }

        if (choice < 1 || choice > 9) {
            printf("Please choose 1-9.\n");
            continue;
        }

        double a, b, result;

        switch (choice) {
            case 1:
                if (!read_double("Enter first number: ", &a)) break;
                if (!read_double("Enter second number: ", &b)) break;
                printf("Result: %.2f\n", add(a, b));
                break;
            case 2:
                if (!read_double("Enter first number: ", &a)) break;
                if (!read_double("Enter second number: ", &b)) break;
                printf("Result: %.2f\n", subtract(a, b));
                break;
            case 3:
                if (!read_double("Enter first number: ", &a)) break;
                if (!read_double("Enter second number: ", &b)) break;
                printf("Result: %.2f\n", multiply(a, b));
                break;
            case 4:
                if (!read_double("Enter first number: ", &a)) break;
                if (!read_double("Enter second number: ", &b)) break;
                if (divide(a, b, &result))
                    printf("Result: %.2f\n", result);
                else
                    printf("Error: division by zero.\n");
                break;
            case 5: {
                long x, y, r;
                printf("Enter first integer: ");
                if (scanf("%ld", &x) != 1) { printf("Invalid integer.\n"); clear_stdin(); break; }
                clear_stdin();
                printf("Enter second integer: ");
                if (scanf("%ld", &y) != 1) { printf("Invalid integer.\n"); clear_stdin(); break; }
                clear_stdin();
                if (modulus(x, y, &r))
                    printf("Result: %ld\n", r);
                else
                    printf("Error: modulus by zero.\n");
                break;
            }
            case 6:
                if (!read_double("Enter base: ", &a)) break;
                if (!read_double("Enter exponent: ", &b)) break;
                printf("Result: %.2f\n", power(a, b));
                break;
            case 7:
                if (!read_double("Enter number: ", &a)) break;
                if (square_root(a, &result))
                    printf("Result: %.2f\n", result);
                else
                    printf("Error: square root of negative number.\n");
                break;
            case 8: {
                int n;
                long long f;
                if (!read_int("Enter non-negative integer: ", &n)) break;
                if (factorial(n, &f))
                    printf("Result: %lld\n", f);
                else
                    printf("Error: factorial of negative number.\n");
                break;
            }
        }
    }
    return 0;
}
