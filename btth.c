#include <stdio.h>
#include <stdlib.h>
void displayMenu() {
    printf("----------------- Integer List Management -----------------\n");
    printf("1. Add an element at any position\n");
    printf("2. Remove an element at any position\n");
    printf("3. Update a value at any position\n");
    printf("4. Search for an element in the array\n");
    printf("5. Display the array\n");
    printf("0. Exit program\n");
    printf("-----------------------------------------------------------\n");
    printf("Please choose an option: ");
}
void displayArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Elements in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *numbers = NULL;
    int size = 0;
    int choice, element, position, i;

    // Initialize an empty array
    numbers = (int *)malloc(0);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add element
                printf("Enter the element to add: ");
                scanf("%d", &element);
                printf("Enter the position to add (0 to %d): ", size);
                scanf("%d", &position);

                if (position < 0 || position > size) {
                    printf("Invalid position.\n");
                    break;
                }

                numbers = (int *)realloc(numbers, (size + 1) * sizeof(int));
                if (numbers == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                for (i = size; i > position; i--) {
                    numbers[i] = numbers[i-1];
                }
                numbers[position] = element;
                size++;
                printf("Successfully added element %d at position %d.\n", element, position);
                break;

            case 2: // Remove element
                if (size == 0) {
                    printf("Array is empty, cannot remove.\n");
                    break;
                }
                printf("Enter the position to remove (0 to %d): ", size - 1);
                scanf("%d", &position);

                if (position < 0 || position >= size) {
                    printf("Invalid position.\n");
                    break;
                }

                element = numbers[position];
                for (i = position; i < size - 1; i++) {
                    numbers[i] = numbers[i+1];
                }

                numbers = (int *)realloc(numbers, (size - 1) * sizeof(int));
                size--;
                printf("Successfully removed element %d at position %d.\n", element, position);
                break;
            case 3:
                if (size == 0) {
                    printf("Array is empty, cannot update.\n");
                    break;
                }
                printf("Enter the position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("Invalid position.\n");
                    break;
                }
                printf("Enter the new value: ");
                scanf("%d", &element);
                numbers[position] = element;
                printf("Successfully updated value at position %d.\n", position);
                break;
            case 4:
                if (size == 0) {
                    printf("Array is empty, cannot search.\n");
                    break;
                }
                printf("Enter the element to search for: ");
                scanf("%d", &element);

                int found = 0;
                printf("Element %d found at position(s): ", element);
                for (i = 0; i < size; i++) {
                    if (numbers[i] == element) {
                        printf("%d ", i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("not found.");
                }
                printf("\n");
                break;
            case 5:
                displayArray(numbers, size);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    free(numbers);
    return 0;
}