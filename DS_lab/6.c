#include <stdio.h>

struct poly {
    int coeff;
    int power;
};

int main() {
    struct poly p1[10], p2[10], p3[20];
    int n1, n2, i, j, k = 0;

    // a. Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter first polynomial terms (coefficient power):\n");
    for(i = 0; i < n1; i++) {
        scanf("%d %d", &p1[i].coeff, &p1[i].power);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter second polynomial terms (coefficient power):\n");
    for(i = 0; i < n2; i++) {
        scanf("%d %d", &p2[i].coeff, &p2[i].power);
    }

    // b. Add polynomials
    i = j = 0;
    
    while(i < n1 && j < n2) {
        if(p1[i].power == p2[j].power) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].power = p1[i].power;
            i++; j++; k++;
        }
        else if(p1[i].power > p2[j].power) {
            p3[k] = p1[i];
            i++; k++;
        }
        else {
            p3[k] = p2[j];
            j++; k++;
        }
    }

    // Copy remaining terms
    while(i < n1) {
        p3[k] = p1[i];
        i++; k++;
    }

    while(j < n2) {
        p3[k] = p2[j];
        j++; k++;
    }

    // Display Result
    printf("\nResultant Polynomial: ");
    for(i = 0; i < k; i++) {
        printf("%dx^%d", p3[i].coeff, p3[i].power);
        if(i != k-1)
            printf(" + ");
    }

    return 0;
}
