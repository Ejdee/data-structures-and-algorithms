#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int flag = false;
        for (int j = 0; j < size - i - 1; j++) { // size-i-1, protoze po kazdym (i) projeti, bude nejvyssi hodnota na konci, nemusime se s ni tedy dale zabyvat
            if(arr[j] > arr[j+1]) {
                flag = true;
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag == false){ // jestli neprobehl zadny swap, vsechny hodnoty jsou serazene a muzeme to ukoncit
            break; // vyhneme se tak projeti cyklu vicekrat nez je treba
        }
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {5,3,2,1,4,8,7,9,6};
    int size = sizeof(arr)/sizeof(int);

    bubbleSort(arr,size);
    printArray(arr,size);

    return 0;
}