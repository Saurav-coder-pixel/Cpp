#include <stdio.h>

int main() {
    int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
    int n = 12, i, j, min, temp;

    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Selection Sort: ");
    for(i=0;i<n;i++) printf("%d ", a[i]);
}


