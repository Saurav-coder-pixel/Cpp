#include <stdio.h>

int main() {
    float arr[100], element;
    int n, pos, i;

    // a) Input an array of float
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d float values:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // b) Ask position and element from user
    printf("Enter position to insert (1 to %d): ", n+1);
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%f", &element);

    // c) Shift elements and insert
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    n++;

    // d) Print updated array
    printf("Updated array:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
