#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

