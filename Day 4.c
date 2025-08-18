#include <stdio.h>
#include <math.h>

// Utility function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

// Merge function using GAP method
void merge(int arr1[], int arr2[], int m, int n) {
    int i, j, gap = m + n;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        // Compare elements in the first array
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) {
                swap(&arr1[i], &arr1[i + gap]);
            }
        }

        // Compare elements between both arrays
        for (j = (gap > m) ? gap - m : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j]) {
                swap(&arr1[i], &arr2[j]);
            }
        }

        // Compare elements in the second array
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap]) {
                    swap(&arr2[j], &arr2[j + gap]);
                }
            }
        }
    }
}

// Driver Code
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, arr2, m, n);

    printf("arr1: ");
    for (int i = 0; i < m; i++)
        printf("%d ", arr1[i]);

    printf("\narr2: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);

    return 0;
}
