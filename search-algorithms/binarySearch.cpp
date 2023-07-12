//serazena array podminkou

#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size-1;
    int mid;

    while(left <= right) {
        mid = left + (right-left) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1,5,7,12,34,67,89,90};
    int size = sizeof(arr)/sizeof(int);
    int target;

    cout << "zadejte hodnotu pro nalezeni: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << endl << "hodnota nalezena na pozici " << result+1;
    } else {
        cout << "hodnota nebyla nalezena" << endl;
    }
}