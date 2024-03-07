#include <stdio.h>

int isSubset(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] == arr2[j]) {
            i++;
            j++;
        } else {
            return 0;  
        }
    }
    return (j == n);
}
int main() {
    int m, n;

    printf("Enter the size of array 1: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of array 1: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of array 2: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter the elements of array 2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    if (isSubset(arr1, m, arr2, n)) {
        printf("Array 2 is a subset of Array 1\n");
    } else {
        printf("Array 2 is not a subset of Array 1\n");
    }
    return 0;
}

