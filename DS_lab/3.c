#include <stdio.h>

int main() {
    float arr[100], element;
    int n, i, pos = -1;

    // a. Input an array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d float values:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // b. Ask element to be deleted
    printf("Enter element to delete: ");
    scanf("%f", &element);

    // c. Search position of element
    for(i = 0; i < n; i++) {
        if(arr[i] == element) {
            pos = i;
            break;
        }
    }

    // If element not found
    if(pos == -1) {
        printf("Element not found in array.\n");
        return 0;
    }

    // d. Delete element by shifting
    for(i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    // e. Print upgraded array
    printf("Updated array:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
