#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    int j;
    int key;

    for(int i = 1; i<size; i++) {
        j = i-1;
        key = arr[i];

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {5,3,2,4,1,7,9,8,6};
    int size = sizeof(arr)/sizeof(int);

    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}