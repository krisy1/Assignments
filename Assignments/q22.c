#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void deleteAtFront(int arr[], int *size) {
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void deleteAtPosition(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void deleteAtEnd(int arr[], int *size) {
    (*size)--;
}
int main() {
    int n, choice, position;
    printf("Enter the initial number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Initial array: ");
    printArray(arr, n);
    printf("Choose deletion type:\n");
    printf("1. Delete at front\n");
    printf("2. Delete at any position\n");
    printf("3. Delete at end\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            deleteAtFront(arr, &n);
            break;
        case 2:
            printf("Enter the position to delete (0 to %d): ", n - 1);
            scanf("%d", &position);
            deleteAtPosition(arr, &n, position);
            break;
        case 3:
            deleteAtEnd(arr, &n);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    printf("Updated array: ");
    printArray(arr, n);
    return 0;
}