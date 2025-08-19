#include <stdio.h>

void findLeaders(int arr[], int n) {
    int leaders[n];   // Temporary array to store leaders
    int count = 0;

    // Last element is always a leader
    int max_from_right = arr[n-1];
    leaders[count++] = max_from_right;

    // Traverse array from right to left
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            max_from_right = arr[i];
            leaders[count++] = arr[i];
        }
    }

    // Print leaders in original order (reverse of collection)
    printf("Leaders: ");
    for (int i = count-1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
