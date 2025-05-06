#include <iostream>
using namespace std;

class Stack {

private:
    static const int MAX = 5;
    int arr[MAX];
    int top;

public:
    Stack() {top = -1;}// Constructure 

    // Push operation 
    void push(int value) {
        if (top == MAX -1){
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = value;
    }

    //pop operation 
    void pop(){

        if (top == -1){
            cout << "Stack Underflow";
            return;
        }
        top--; // Remove top element
    }

    // Peek (get top element)
    int peek(){
        if (top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty 
    bool isEmpty(){
        return top == -1;

    }

    void display(){
        if (top == -1){
            cout << "Stack is empty!"<< endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--){
            cout << arr[i] <<" ";
        }
    }
};

int main(){

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output : Stack: 30 20 10

    s.pop();
    cout << "After pop: ";
    s.display(); // Output : Stack 20 10 

    cout << "Top elements: " << s.peek() << endl; // Output: 20

    return 0;

}
