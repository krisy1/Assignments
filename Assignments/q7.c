#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

long long decimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1;
    while (n != 0) {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main() {
    int choice, num;
    long long binary;
    
    printf("Enter 1 for Binary to Decimal, 2 for Decimal to Binary: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter binary number: ");
        scanf("%lld", &binary);
        printf("Decimal: %d\n", binaryToDecimal(binary));
    } else if (choice == 2) {
        printf("Enter decimal number: ");
        scanf("%d", &num);
        printf("Binary: %lld\n", decimalToBinary(num));
    } else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}
