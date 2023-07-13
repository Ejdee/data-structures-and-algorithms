#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
    int min;
    for (int i = 0; i < size-1; i++) {
        min = i;

        for (int j = i+1; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int arr[] = {5,2,1,4,3,7,9,8,6};
    int size = sizeof(arr)/sizeof(int);

    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}