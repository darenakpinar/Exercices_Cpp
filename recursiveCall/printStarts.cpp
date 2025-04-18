#include <iostream>
using namespace std;

void printStar(int totalRows ) {
    int currentStar = 1
    if (totalRows <= 0) return;  // base case: done printing all rows

    if (currentStar <= totalRows) {
        cout << "*";
        printStar(totalRows, currentStar + 1);  // print next star in this row
    } else {
        cout << endl;
        printStar(totalRows - 1, 1);  // move to next row, reset star count
    }
}

int main() {
    printStar(4);  // only one call, one function!
    return 0;
}