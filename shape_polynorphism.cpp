#include <iostream>
#include <cmath>
#include <vector>
#include <memory> // For smart pointers
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual functions enforce that derived classes must implement these methods
    virtual double area() const = 0;
    virtual void display() const = 0;
    
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() { }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor to initialize the radius
    Circle(double r) : radius(r) { }
    
    // Override the area method using the circle area formula (πr²)
    double area() const override {
        return M_PI * radius * radius;
    }
    
    // Override the display method to show circle details
    void display() const override {
        cout << "Circle: Radius = " << radius 
             << ", Area = " << area() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    // Constructor to initialize width and height
    Rectangle(double w, double h) : width(w), height(h) { }
    
    // Override the area method using the rectangle area formula (width * height)
    double area() const override {
        return width * height;
    }
    
    // Override the display method to show rectangle details
    void display() const override {
        cout << "Rectangle: Width = " << width 
             << ", Height = " << height 
             << ", Area = " << area() << endl;
    }
};

int main(){
    // Use a vector of smart pointers to store different shapes.
    // This allows automatic memory management.
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    // Loop through and display each shape's details
    for(const auto &shape : shapes){
        shape->display();
    }

    return 0;
}
