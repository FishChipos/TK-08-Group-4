#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Arithmetic functions.
// TODO: Function definitions.
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    bool shouldClose = false;

    puts("=== CALCULATOR ===\n");
    
    while (!shouldClose) {
        char input[128];

        double left = 0;
        double right = 0;
        double result = 0;

        bool operationFound = false;

        printf("%s\n", "Enter an expression with only one operation. (type exit to close)");
        fgets(input, 128, stdin);

        // Remove trailing newline from fgets().
        input[strcspn(input, "\n")] = '\0';

        // Check if user wants to close.
        if (strcmp(input, "exit") == 0) {
            shouldClose = true;
            break;
        }

        for (char *c = input; *c != '\0'; c++) {
            // Skip newlines.
            if (*c == ' ') {
                continue;
            }

            if (isdigit(*c)) {
                

                continue;
            }
            
            switch (*c) {
                case '+':
                    operationFound = true;
                    break;
                case '-':
                    operationFound = true;
                    break;
                case '*':
                    operationFound = true;
                    break;
                case '/':
                    operationFound = true;
                    break;
                default:
                    puts("Invalid character found.");
                    break;
            }
        }

        printf("Result: %lf\n\n", result);
    }

    // End message.
    puts("\nThank you for using our calculator!");

    return 0;
}

double multiply(double a, double b) {
    return a * b;
}

double add(double a, double b) {
    return a + b;
}
