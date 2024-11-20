#include <stdio.h>
void rotateArray(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int lastElement = arr[size - 1];
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
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
    printf("Initial array: ");
    printArray(arr, n);
    rotateArray(arr, n);
    printf("Array after rotation: ");
    printArray(arr, n);
    return 0;
}