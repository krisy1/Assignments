#include <stdio.h>
void checkEvenOdd(int marks[], int size) {
    printf("Even/Odd status of scores:\n");
    for (int i = 0; i < size; i++) {
        if (marks[i] % 2 == 0) {
            printf("Student %d: %d is Even\n", i + 1, marks[i]);
        } else {
            printf("Student %d: %d is Odd\n", i + 1, marks[i]);
        }
    }
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
    checkEvenOdd(marks, n);
    return 0;
}