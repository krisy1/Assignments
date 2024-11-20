#include <stdio.h>
void printDuplicates(int arr[], int size) {
    int foundDuplicate = 0;
    int visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (visited[i] == 1) {
            continue;
        }
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1;
                foundDuplicate = 1;
            }
        }
        if (foundDuplicate) {
            printf("%d ", arr[i]);
            foundDuplicate = 0;
        }
    }
    if (!foundDuplicate) {
        printf("-1");
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Duplicates in the array: ");
    printDuplicates(arr, n);
    return 0;
}