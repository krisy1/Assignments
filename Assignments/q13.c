#include <stdio.h>
int findFirst99(int marks[], int size) {
    for (int i = 0; i < size; i++) {
        if (marks[i] == 99) {
            return i + 1;
        }
    }
    return -1;
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
    int position = findFirst99(marks, n);

    if (position != -1) {
        printf("The first student who scored 99 is Student %d.\n", position);
    } else {
        printf("No student scored 99.\n");
    }
    return 0;
}