#include <stdio.h>
void increaseMarks(int marks[], int size) {
    for (int i = 0; i < size; i++) {
        marks[i] += 5;
    }
}
void printMarks(int marks[], int size) {
    printf("Updated Marks:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
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
    increaseMarks(marks, n);
    printMarks(marks, n);

    return 0;
}