#include <stdio.h>
void findMaxMin(int marks[], int size, int *max, int *min) {
    *max = marks[0];
    *min = marks[0];
    for (int i = 1; i < size; i++) {
        if (marks[i] > *max) {
            *max = marks[i];
        }
        if (marks[i] < *min) {
            *min = marks[i];
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
    int max, min;
    findMaxMin(marks, n, &max, &min);
    printf("Maximum score: %d\n", max);
    printf("Minimum score: %d\n", min);
    return 0;
}