#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef enum {
    OPERATION_ADD = 0,
    OPERATION_SUBTRACT,
    OPERATION_MULTIPLY,
    OPERATION_DIVIDE
} Operation;

const char operationChars[] = {'+', '-', '*', '/'};

// Arithmetic functions.

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Parsing functions.

// Parses a string for a number given an inclusive start and end index.
double parseNumber(char *string, size_t start, size_t end);

int main() {
    bool shouldClose = false;

    puts("=== CALCULATOR ===\n");
    
    while (!shouldClose) {
        char input[128];

        double left = 0;
        double right = 0;
        double result = 0;

        Operation operation = -1;
        size_t operationIndex;

        printf("%s\n", "Enter an expression with only one operation. (type exit to close)");
        fgets(input, 128, stdin);

        // Remove trailing newline from fgets().
        input[strcspn(input, "\n")] = '\0';

        // Check if user wants to close.
        if (strcmp(input, "exit") == 0) {
            shouldClose = true;
            break;
        }

        // Find the operation.
        for (char *c = input; *c != '\0'; c++) {
            // Skip newlines.
            if (*c == ' ') {
                continue;
            }

            for (Operation operationCandidate = 0; operationCandidate < 4; operationCandidate++) {
                if (*c == operationChars[operationCandidate]) {
                    operation = operationCandidate;
                    operationIndex = c - input;
                    break;
                }
            }
        }

        // Parse the left and right numbers.
        left = parseNumber(input, 0, operationIndex - 1);
        right = parseNumber(input, operationIndex + 1, strlen(input) - 1);

        switch (operation) {
            case OPERATION_ADD:
                result = add(left, right);
                break;
            case OPERATION_SUBTRACT:
                result = subtract(left, right);
                break;
            case OPERATION_MULTIPLY:
                result = multiply(left, right);
                break;
            case OPERATION_DIVIDE:
                result = divide(left, right);
                break;
            default:
                puts("No operation found!\n");
                continue;
        }

        printf("Result: %lf\n\n", result);
    }

    // End message.
    puts("\nThank you for using our calculator!");

    return 0;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b){
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
    	puts("Can't divide by zero.");
		return NAN;
	}
	
	return a / b;
}

double parseNumber(char *string, size_t start, size_t end) {
    double number = 0;
    size_t digit = end - start;

    for (size_t i = start; i <= end; i++) {
        number += (string[i] - '0') * pow(10, digit);
        digit--;
    }

    return number;
}
