#include <iostream>
// INSERTION SORT builds a sorted list one item ar a time 

void insertionSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i -1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main(){

    int arr[] = {5, 2, 9, 1, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n); 

    for (int num: arr){
        std::cout << num << " ";

    }
    return 0;
}