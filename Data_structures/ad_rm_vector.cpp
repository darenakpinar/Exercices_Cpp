#include <iostream>
#include <vector>

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for(int num : v){
        cout << num << " ";
    }
    cout << endl;

    v.pop_back(); // Removes last element 

    cout << "After  pop_back: ";
    for (int num : v){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}