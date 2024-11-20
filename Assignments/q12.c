#include <stdio.h>

void printGrades(int marks[], int size) {
    printf("Grades of Students:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: ", i + 1);
        if (marks[i] >= 75) {
            printf("A Grade\n");
        } else if (marks[i] >= 60) {
            printf("B Grade\n");
        } else if (marks[i] >= 40) {
            printf("C Grade\n");
        } else {
            printf("D Grade\n");
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
    printGrades(marks, n);
    return 0;
}