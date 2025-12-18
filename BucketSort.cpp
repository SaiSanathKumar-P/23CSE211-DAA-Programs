#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the values (0 to 100):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int bucket[101] = {0};
    for (int i = 0; i < n; i++) {
        bucket[a[i]]++;
    }
    printf("Sorted array: ");
    for (int value = 0; value <= 100; value++) {
        while (bucket[value] > 0) {
            printf("%d ", value);
            bucket[value]--;
        }
    }
    return 0;
}
