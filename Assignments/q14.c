#include <stdio.h>
void findAll99(int marks[], int size) {
    int count = 0;
    printf("Students who scored 99:\n");
    for (int i = 0; i < size; i++) {
        if (marks[i] == 99) {
            printf("Student %d\n", i + 1);
            count++;
        }
    }
    if (count == 0) {
        printf("No student scored 99.\n");
    } else {
        printf("Total number of students who scored 99: %d\n", count);
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
    findAll99(marks, n);
    return 0;
}