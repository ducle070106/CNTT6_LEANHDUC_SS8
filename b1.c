#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int array_length = sizeof(numbers) / sizeof(numbers[0]);
    printf("The elements of the array are:\n");
    for (int i = 0; i < array_length; i++) {
        printf("Element at index %d has value: %d\n", i, numbers[i]);
    }
    printf("\nLength of the array is: %d\n", array_length);
    return 0;
}