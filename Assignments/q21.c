#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertAtFront(int arr[], int *size, int value) {
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;  
}
void insertAtPosition(int arr[], int *size, int value, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;  
    (*size)++;             
}
void insertAtEnd(int arr[], int *size, int value) {
    arr[*size] = value; 
    (*size)++;     
}
int main() {
    int n, choice, value, position;
    printf("Enter the initial number of elements in the array: ");
    scanf("%d", &n);
       int arr[n + 1];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Initial array: ");
    printArray(arr, n);
    printf("Choose insertion type:\n");
    printf("1. Insert at front\n");
    printf("2. Insert at any position\n");
    printf("3. Insert at end\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the value to insert at front: ");
            scanf("%d", &value);
            insertAtFront(arr, &n, value);
            break;
        case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the position to insert (0 to %d): ", n);
            scanf("%d", &position);
            insertAtPosition(arr, &n, value, position);
            break;
        case 3:
            printf("Enter the value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(arr, &n, value);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    printf("Updated array: ");
    printArray(arr, n);
    return 0;
}