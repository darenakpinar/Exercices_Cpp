#include <iostream>
// bubble sort basic but inefficent.
void bubbleSort(int arr[], int n ){
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j < n -i-1; j++ ){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = { 9, 6, 7,5 };

    bubbleSort(arr, 4);
    for (int i = 0; i < 4; i++)
    {
        std::cout << arr[i] <<" ";
    }
    std::cout<<std::endl;
    return 0;
}