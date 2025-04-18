#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *next;
    Node *prev;

    Node (int value) : data(value), next(nullptr), prev(nullptr){}
};
class DoubleLinkedList {

private:
    Node *head;

public:
    DoubleLinkedList() { head = nullptr; }

    void insertAtBeginning(int value){

        Node *newNode = new Node(value);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value){

        Node *newNode = new Node(value);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value){
        if (head == nullptr)return;

        Node *temp = head;

        while (temp != nullptr && temp->data != value){
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr){
            temp->next->prev = temp->prev;
        }else{
            head = temp->next;
        }


    }

    void displayForward(){

        Node * temp = head;
        while (temp != nullptr){

            cout << temp->data << " <->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackwards(){
        if(head == nullptr) return;

        Node *temp = head;
        while (temp ->next != nullptr){
            temp = temp->next;
        }
        while (temp != nullptr){
            cout << temp->data << "<->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main(){

    DoubleLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Doubly linked List (Forward)";
    dll.displayForward();

    cout << "Doubly linked list (Backwards)";
    dll.displayBackwards();
    
    dll.deleteNode(20);
    cout << "Doubly linked list after deleting 20 (Forward)";
    dll.displayForward();

    return 0;
}