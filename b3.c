#include <stdio.h>

int main() {
    int numbers[5] = {1, 3, 5, 7, 9}; // Example with no even numbers
    int i;
    int found_even = 0;
    printf("The even numbers in the array are:\n");
    for (i = 0; i < 5; i++) {
        // Check if the element is even
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
            found_even = 1;
        }
    }
    if (found_even == 0) {
        printf("The array contains no even numbers.");
    }
    printf("\n");
    return 0;
}