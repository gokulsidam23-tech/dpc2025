#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a portion of string in place
void reverse(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Function to trim extra spaces and return cleaned length
int cleanSpaces(char *s) {
    int i = 0, j = 0;
    while (s[j]) {
        // Skip multiple spaces
        while (isspace(s[j]) && (j == 0 || isspace(s[j-1]))) j++;
        s[i++] = s[j++];
    }
    // Remove trailing space if any
    if (i > 0 && isspace(s[i-1])) i--;
    s[i] = '\0';
    return i;
}

void reverseWords(char *s) {
    int n = cleanSpaces(s);

    // Step 1: reverse the entire string
    reverse(s, 0, n-1);

    // Step 2: reverse each word
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s, start, i-1);
            start = i + 1;
        }
    }
}

int main() {
    char s[10005];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline from fgets if present
    s[strcspn(s, "\n")] = '\0';

    reverseWords(s);

    printf("Output: \"%s\"\n", s);

    return 0;
}
