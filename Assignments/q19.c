#include <stdio.h>
int findPeakElement(int marks[], int size) {
    if (size == 1 || marks[0] >= marks[1]) 
        return 0;
    if (marks[size - 1] >= marks[size - 2]) 
        return size - 1;
    for (int i = 1; i < size - 1; i++) {
        if (marks[i] >= marks[i - 1] && marks[i] >= marks[i + 1]) {
            return i;
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
    int peakIndex = findPeakElement(marks, n);
    if (peakIndex != -1) {
        printf("Peak element found at Student %d with score: %d\n", peakIndex + 1, marks[peakIndex]);
    } else {
        printf("No peak element found.\n");
    }
    return 0;
}