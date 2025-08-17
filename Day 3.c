#include <stdio.h>

int findDuplicate(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Detect cycle (like Linked List cycle detection)
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: Find the cycle start (duplicate number)
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;  // duplicate number
}

int main() {
    // Example test case
    int arr[] = {3, 1, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // n = size - 1

    int duplicate = findDuplicate(arr, n);
    printf("Duplicate number: %d\n", duplicate);

    return 0;
}
