#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
        double result = 0;

        printf("%s\n", "Enter an expression with only one operation. (type exit to close)");
        fgets(input, 128, stdin);

        // Remove trailing newline from fgets().
        input[strcspn(input, "\n")] = '\0';

        // Check if user wants to close.
        if (strcmp(input, "exit") == 0) {
            shouldClose = true;
            break;
        }

        // TODO: Input parsing.

        printf("Result: %lf\n\n", result);
    }

    // End message.
    puts("\nThank you for using our calculator!");

    return 0;
}