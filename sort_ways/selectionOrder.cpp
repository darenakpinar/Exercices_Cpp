#include <iostream>

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1;i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j ++){
            if (arr[j]< arr[minIndex]){
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[] = {5, 2, 3, 9, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int num : arr)
    {
        std::cout << num << " ";
    }
    return 0;
}