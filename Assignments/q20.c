#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int countPrimes(int marks[], int size) {
    int primeCount = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(marks[i])) {
            primeCount++;
        }
    }
    return primeCount;
}
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int marks[n];
    printf("Enter the marks of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    int primeCount = countPrimes(marks, n);
    printf("The number of prime numbers in the array: %d\n", primeCount);
    return 0;
}