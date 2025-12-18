#include <stdio.h>
int main() {
    int n;
    printf("ENTER NO. OF ELEMENTS: ");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE VALUES: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int child = i;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (arr[child] > arr[parent]) {
                int temp = arr[child];
                arr[child] = arr[parent];
                arr[parent] = temp;
                child = parent;
            } else {
                break;
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int parent = 0;
        while (1) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int biggest = parent;
            if (left < i && arr[left] > arr[biggest])
                biggest = left;
            if (right < i && arr[right] > arr[biggest])
                biggest = right;
            if (biggest != parent) {
                int t = arr[parent];
                arr[parent] = arr[biggest];
                arr[biggest] = t;
                parent = biggest;
            } 
            else {
                break;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
