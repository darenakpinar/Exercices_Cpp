#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() { head = nullptr; }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { 
            head = newNode;
            head->next = head;  // Point to itself
            return;
        }
        Node* temp = head;
        while (temp->next != head) {  
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { 
            head = newNode;
            head->next = head;  
            return;
        }
        Node* temp = head;
        while (temp->next != head) {  
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Delete a node
    void deleteNode(int value) {
        if (head == nullptr) return;

        Node* temp = head;
        Node* prev = nullptr;

        // Case: If the head node is to be deleted
        if (head->data == value) {
            while (temp->next != head) { 
                temp = temp->next;
            }
            if (head == head->next) {  
                delete head;
                head = nullptr;
                return;
            }
            temp->next = head->next; 
            delete head;
            head = temp->next;
            return;
        }

        // Deleting a node that is not the head
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        if (temp == head) return;  
        prev->next = temp->next;
        delete temp;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Circular Linked List: ";
    cll.display();

    cll.deleteNode(20);
    cout << "After deleting 20: ";
    cll.display();

    return 0;
}
