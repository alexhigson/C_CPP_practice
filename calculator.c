#include <stdio.h>
#include <stdlib.h>

double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double find_result(double num1, double num2, char operator);

int main() {

    double num1, num2;
    char operator;

    // get first number from user
    while (1) {

        printf("Welcome to your calculator. Please enter the number you want to add to, subtract from, multiply, or divide. This can be any positive or negative integer or decimal: ");

        if (scanf("%lf", &num1) == 1) {
            break;
        } else {
            printf("You haven't entered a valid number. Please enter any positive or negative integer or decimal:\n");
            while (getchar() != '\n'); // clear input buffer
        }

    }

    // get operator choice from user
    while (1) {

        printf("\nNow, please select the operation you want to perform. Enter + for addition, - for subtraction, * for multiplication or / for division: ");

        scanf(" %c", &operator); // space before %c to skip whitespace
        
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
            break;
        } else {
            printf("You haven't entered a valid operator. Please enter +, -, * or /.\n");
            while (getchar() != '\n'); // clear input buffer
        }

    }

    // get second number from user
    while (1) {

        printf("\nNow, please enter the number you want to add, subtract, multiply by, or divide by. This can be any positive or negative integer or decimal: ");

        if (scanf("%lf", &num2) == 1) {
            break;
        } else {
            printf("You haven't entered a valid number. Please enter any positive or negative integer or decimal:\n");
            while (getchar() != '\n'); // clear input buffer
        }

    }


    // show result to user
    double result = find_result(num1, num2, operator);
    if (result != -1) {
        printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    } else {
        printf("This is not a valid calculation. Please try again.\n");
    }

    return 0;


}

double add(double num1, double num2) {

    return num1 + num2;

}

double subtract(double num1, double num2) {

    return num1 - num2;
    
}

double multiply(double num1, double num2) {

    return num1 * num2;
    
}

double divide(double num1, double num2) {

    if (num2 != 0) {
        return num1 / num2;
    }
    return -1; // handling invalid zero division operation
    
}

double find_result(double num1, double num2, char operator) {

    switch (operator) {
        case '+':
            return add(num1, num2);
        case '-':
            return subtract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1, num2);
        default:
            return -1;  // Return -1 for invalid operation
    }

}