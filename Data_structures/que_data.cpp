#include <iostream> 
using namespace std;

class Queue {
private:
    static const int MAX = 5;
    int arr[MAX];
    int front, rear;

public:
    Queue(){

        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {

            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " added to queue." << endl;
    }

    void dequeue(){
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
    }
    int getFront(){
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){

        return (front == -1 || front > rear);

    }

    bool isFull(){
        return (rear == MAX -1);
    }


    void display(){
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue:";
        for (int i = front; i <=rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main (){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // Should show "Queue Overflow!"

    q.display();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;

}