#include <iostream>

using namespace std;

void merge(int* arr, int l, int m, int r, int* temp) { // l=left,r=right,m=middle
    int i = l;
    int j = m+1;
    int k = l;

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        } else {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    while(i<=m){
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=r){
        temp[k]=arr[j];
        k++;
        j++;
    }

    for(int a=l; a<=r; a++){
        arr[a]=temp[a];
    }
}

void mergeSort(int* arr, int l, int r){  //l=left, r=right
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        int temp[r+1];
        merge(arr, l, m, r, temp);
    }
}

void printArray(int* arr, size_t size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {4,23,564,34,43,452,98,427,6356,73,6,45,62,456,234,5,2346,245};
    size_t size = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, size-1);
    printArray(arr, size);

    return 0;
}