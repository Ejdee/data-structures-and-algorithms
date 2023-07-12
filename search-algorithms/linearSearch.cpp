#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 5, 23, 543, 7, 2, 34, 5, 23, 22, 67};
    int target;
    int size = sizeof(arr)/sizeof(int);

    cout << "zadejte hodnotu pro nalezeni: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "hodnota nalezena na pozici " << result+1 << endl; 
    } else {
        cout << "hodnota nebyla nalezena" << endl;
    }

    return 0;
}