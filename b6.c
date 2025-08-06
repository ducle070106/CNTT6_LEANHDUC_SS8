#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int i;
    printf("Original array: {");
    for (i = 0; i < 5; i++) {
        printf("%d", numbers[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("}\n");
    for (i = 0; i < 5; i++) {
        if (numbers[i] % 2 != 0) {
            numbers[i] += 2;
        } else {
            numbers[i] += 3;
        }
    }
    printf("Modified array: {");
    for (i = 0; i < 5; i++) {
        printf("%d", numbers[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("}\n");
    return 0;
}