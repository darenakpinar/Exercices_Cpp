#include <iostream> 
#include <cmath>
using namespace std;

class Point {

private:
    // Cordinates
    int x;
    int y;
    
public:
    Point(int x_cor, int y_cor): x(x_cor), y(y_cor){ }


    double distanceFromOrigin()const{
        
        return sqrt(pow(x, 2)+pow(y,2)); 
    }

    void displayPoint()const{

        cout << "Cordinates of the point: (" << x << " , " << y << ")"<< endl;
        
    }
};
int main(){

    Point A(3, 4);
    Point B(5, 7);

    A.displayPoint();
    cout << "Distance from origin: " << A.distanceFromOrigin() << endl;

    B.displayPoint();
    cout << "Distance from origin: " << A.distanceFromOrigin() << endl;

    return 0;


}