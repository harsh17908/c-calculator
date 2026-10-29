/*
 * Calculator — console utility in C
 * Author: Harsh Verma (github.com/harsh17908)
 * Features: add, subtract, multiply, divide, modulus, power
 * Build: gcc calculator.c -o calculator
 * Run: ./calculator  (Windows: calculator.exe)
 */
#include <stdio.h>
#include <stdlib.h>

static void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

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

static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        printf("Invalid choice. Enter a number 1-7.\n");
        clear_stdin();
        return 0;
    }
    clear_stdin();
    return 1;
}

static double add(double a, double b) { return a + b; }
static double subtract(double a, double b) { return a - b; }
static double multiply(double a, double b) { return a * b; }
static int divide(double a, double b, double *result) {
    if (b == 0.0) return 0;
    *result = a / b;
    return 1;
}

static void print_menu(void) {
    printf("\n==== C Calculator ====\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus (integers)\n");
    printf("6. Power (a^n, n >= 0)\n");
    printf("7. Exit\n");
}

int main(void) {
    int choice = 0;

    while (1) {
        print_menu();
        if (!read_int("Enter choice (1-7): ", &choice)) continue;

        if (choice == 7) {
            printf("Goodbye.\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Please choose 1-7.\n");
            continue;
        }

        double a, b, result;

        if (choice >= 1 && choice <= 4) {
            if (!read_double("Enter first number: ", &a)) continue;
            if (!read_double("Enter second number: ", &b)) continue;
        }

        switch (choice) {
            case 1:
                printf("Result: %.2f\n", add(a, b));
                break;
            case 2:
                printf("Result: %.2f\n", subtract(a, b));
                break;
            case 3:
                printf("Result: %.2f\n", multiply(a, b));
                break;
            case 4:
                if (divide(a, b, &result))
                    printf("Result: %.2f\n", result);
                else
                    printf("Error: division by zero.\n");
                break;
            case 5: {
                long x, y;
                printf("Enter first integer: ");
                if (scanf("%ld", &x) != 1) { printf("Invalid integer.\n"); clear_stdin(); break; }
                clear_stdin();
                printf("Enter second integer: ");
                if (scanf("%ld", &y) != 1) { printf("Invalid integer.\n"); clear_stdin(); break; }
                clear_stdin();
                if (y == 0) printf("Error: modulus by zero.\n");
                else printf("Result: %ld\n", x % y);
                break;
            }
            case 6: {
                double base;
                int exp;
                if (!read_double("Enter base: ", &base)) break;
                if (!read_int("Enter exponent (n >= 0): ", &exp)) break;
                if (exp < 0) { printf("Exponent must be >= 0.\n"); break; }
                double p = 1.0;
                for (int i = 0; i < exp; i++) p *= base;
                printf("Result: %.2f\n", p);
                break;
            }
        }
    }
    return 0;
}
