// Insertion sort Code In C

#include <stdio.h>

int array[100], i, j, currentElement, numElements, maxShifts, shiftCount = 0;
float shiftPercentage;

int main() {
    printf("\nHow many elements do you want in the array? ");
    scanf("%d", &numElements);

    printf("\nEnter elements: ");
    for (i = 0; i < numElements; i++) {
        scanf("%d", &array[i]);
    }

    // Insertion Sort
    for (j = 1; j < numElements; j++) {
        currentElement = array[j];
        i = j - 1;
        while ((i >= 0) && (currentElement < array[i])) {
            array[i + 1] = array[i];
            i = i - 1;
            shiftCount++;
        }
        array[i + 1] = currentElement;
    }

    maxShifts = (numElements * (numElements - 1)) / 2;  // Maximum possible shifts
    shiftPercentage = ((float) shiftCount / maxShifts) * 100;

    printf("\nArray elements after sort: ");
    for (i = 0; i < numElements; i++) {
        printf("%d\t", array[i]);
    }

    printf("\nNumber of shifts = %d", shiftCount);
    printf("\nPercentage of shifts = %.2f%%", shiftPercentage);

    if (shiftPercentage < 33.0) {
        printf("\nBest case complexity");
    } else if (shiftPercentage < 66.0) {
        printf("\nAverage case complexity");
    } else {
        printf("\nWorst case complexity");
    }

    return 0;
}


// How many elements do you want in the array? 5

// Enter elements: 22 33 11 55 10

// Array elements after sort: 10   11      22      33      55
// Number of shifts = 6
// Percentage of shifts = 60.00%
// Average case complexity