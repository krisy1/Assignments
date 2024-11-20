#include <stdio.h>
#include <math.h>
void displayMenu() {
    printf("Simple Calculator Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Logarithmic values\n");
    printf("6. Square roots\n");
    printf("7. Exit\n");
}
int main() {
    int choice;
    double num1, num2, result;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3: 
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    result = log(num1);
                    printf("Logarithm (base e) of %.2lf: %.2lf\n", num1, result);
                } else {
                    printf("Error: Logarithm is only defined for positive numbers.\n");
                }
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("Square root of %.2lf: %.2lf\n", num1, result);
                } else {
                    printf("Error: Square root is not defined for negative numbers.\n");
                }
                break;
            case 7:
                printf("Exiting the calculator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option (1-7).\n");
        }
    }
    return 0;
}