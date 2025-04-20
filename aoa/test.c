#include <stdio.h>
#include <conio.h>

//sawp variabels 
void swap (int *a, int *b){
    int temp = *a;
    *a  = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(arr [j] < pivot){
            i++;
            swap (&arr[i],&arr[j]);
        }
    }}
    // Quick Sort 
    void quicksort(int arr[], int low, int high){
        if (low<high){
            int pi = partition(arr, low, high);

            quicksort(arr, low, pi - 1);
            quicksort(arr, pi+1, high);
        }
    }

    // funtion to print thee sorteddddd arrray lessss gooooooo
    void printArray(int arr[], int size){
        for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        printf("\n");    
    }

    // Maiiiinn codeeee

    int main(){
        int arr[]= {10, 7, 8, 9, 1, 5};
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Print Orignal array");
        printArray(arr, n);

        quicksort(arr, 0, n - 1); // Corrected function name

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
    }

