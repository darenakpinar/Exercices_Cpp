#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 5;  // Stack size inside class (Encapsulation)
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }  // Constructor initializes top at -1

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;  // Remove top element
    }

    // Peek (get top element)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Get the current size of the stack
    int size() {
        return top + 1;
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // This should show "Stack Overflow!"

    s.display();

    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.pop();
    s.pop();
    s.display();

    return 0;
}
