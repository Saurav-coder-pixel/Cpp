#include <stdio.h>

int main() {
    float arr[100], element;
    int n, i, pos = 0;

    // a) Input an array of float
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d float values in sorted order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter element to insert: ");
    scanf("%f", &element);

    // b) Search for the position to insert
    for(i = 0; i < n; i++) {
        if(arr[i] > element) {
            pos = i;
            break;
        }
    }

    // If element is greater than all values, insert at end
    if(i == n) {
        pos = n;
    }

    // c) Shift elements to make space
    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    n++;

    // d) Print updated array
    printf("Updated sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
