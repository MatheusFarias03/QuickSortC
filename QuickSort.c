// QuickSort.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* myArray, int iniPos, int finPos) {

    int pivot = iniPos;
    for (int i = iniPos + 1; i < finPos; i++) {
        if (myArray[i] <= myArray[pivot]) {
            if (myArray[pivot] < myArray[pivot + 1]) {
                // First swap (pivot and after pivot)
                myArray[pivot] = myArray[pivot + 1] - myArray[pivot];
                myArray[pivot + 1] = myArray[pivot + 1] - myArray[pivot];
                myArray[pivot] = myArray[pivot + 1] + myArray[pivot];

                // Seccond swap (with the smaller element)
                myArray[pivot] = myArray[i] - myArray[pivot];
                myArray[i] = myArray[i] - myArray[pivot];
                myArray[pivot] = myArray[i] + myArray[pivot];

                pivot++;
            }
            else if (myArray[i] == myArray[pivot + 1]) {
                // Just swap once
                myArray[pivot] = myArray[pivot + 1] - myArray[pivot];
                myArray[pivot + 1] = myArray[pivot + 1] - myArray[pivot];
                myArray[pivot] = myArray[pivot + 1] + myArray[pivot];

                pivot++;
            }
        }
    }
    return pivot;
}


void quickSort(int* myArray, int iniPos, int finPos) {
    if (iniPos < finPos) {
        int pivot = partition(myArray, iniPos, finPos);
        quickSort(myArray, iniPos, pivot);
        quickSort(myArray, pivot+1, finPos);
    }
}


void printArray(int* myArray, int vectorSize) {
    for (int i = 0; i < vectorSize; i++) {
        printf("%i ", myArray[i]);
    }
}


int main()
{
    //User input
    int vectorSize;
    printf("Type the size of the array: ");
    scanf_s("%d", &vectorSize);

    // Variable sized array
    int* myArray = malloc(sizeof(int)*vectorSize);

    // Random number allocation
    srand(time(0));
    for (int i = 0; i < vectorSize; i++) {
        myArray[i] = rand() % 100;
    }

    printf("\nUnordered Array:\n");
    printArray(myArray, vectorSize);
    quickSort(myArray, 0, vectorSize);
    printf("\n\nOrdered Array:\n");
    printArray(myArray, vectorSize);
    printf("\n");

    // Remove array from memory
    free(myArray);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

