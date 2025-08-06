#include <stdio.h>

int main() {
    int numbers[5] = {25, 12, 45, 8, 30};
    int i;
    int max = numbers[0];
    int min = numbers[0];
    for (i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("The maximum element in the array is: %d\n", max);
    printf("The minimum element in the array is: %d\n", min);
    return 0;
}