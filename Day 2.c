#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    // sum of numbers from 1 to n
    long long total = (long long)n * (n + 1) / 2;

    long long arrSum = 0;
    for (int i = 0; i < n - 1; i++) {
        arrSum += arr[i];
    }

    return (int)(total - arrSum);
}

int main() {
    // Example test case
    int arr[] = {1, 2, 4, 5};
    int n = 5; // because array size is n-1, so here n = 5

    int missing = findMissingNumber(arr, n);
    printf("Missing number: %d\n", missing);

    return 0;
}
