#include <stdio.h>
#include <stdlib.h>

int main() {
    int numberOfElements;
    int *numbers;
    int i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numberOfElements);
    if (numberOfElements <= 0) {
        printf("The number of elements must be greater than 0.\n");
        return 1;
    }
    numbers = (int *)malloc(numberOfElements * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d odd integers:\n", numberOfElements);
    for (i = 0; i < numberOfElements; i++) {
        do {
            printf("Element %d: ", i + 1);
            scanf("%d", &numbers[i]);
            if (numbers[i] % 2 == 0) {
                printf("Error: Please enter an odd number.\n");
            }
        } while (numbers[i] % 2 == 0);
    }
    printf("\nThe odd numbers you entered are:\n");
    for (i = 0; i < numberOfElements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);
    return 0;
}