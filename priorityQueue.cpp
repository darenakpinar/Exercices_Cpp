#include<iostream>

using namespace std;
class PriorityQueue{
  //Do not modify public part
  public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& m);
    ~PriorityQueue();

    PriorityQueue operator*(const PriorityQueue& m) const;
    PriorityQueue operator+(const PriorityQueue& m) const;
    PriorityQueue& operator=(const PriorityQueue& m);

    void insert(int key, int val);
    int get_max() const;
    bool pop_max();

    void print_list() const;

  private:
    struct Cell{
      int key;
      int val;
      Cell* next;
    };
    Cell* head; //head of the list of elements
    
    //add all private methods you need here

};

//Do not modify
PriorityQueue::PriorityQueue() {
  head = nullptr;
}

//Do not modify
PriorityQueue::~PriorityQueue() {
  Cell* pc = head;
  while (pc) {
    pc = pc->next;
    delete head;
    head = pc;
  }
}

//Do not modify
void PriorityQueue::print_list() const {
  Cell* pc = head;
  while (pc) {
    cout << "(" << pc->key << ", " << pc->val<<")"<<endl;
    pc = pc->next;
  }
}

//Do not modify
PriorityQueue::PriorityQueue(const PriorityQueue& m){
  head = nullptr;
  Cell*  pc = m.head;
  while (pc) {
    insert(pc->key, pc->val);
    pc = pc->next;
  }
}

//Exercise 1
void PriorityQueue::insert(int key, int val) {

    // 1) Search for existing cell
    Cell* prev = nullptr;
    Cell* curr = head;
    while (curr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr) {
        // Found existing cell
        if (val > 0) {
            // Update its priority
            curr->val = val;
            // Remove from its current position
            if (prev) prev->next = curr->next;
            else        head       = curr->next;
            // Re-insert in sorted order (higher val -> higher priority)
            Cell* p = nullptr;
            Cell* q = head;
            while (q && q->val >= curr->val) {
                p = q;
                q = q->next;
            }
            if (!p) {
                // New head
                curr->next = head;
                head       = curr;
            } else {
                curr->next = q;
                p->next    = curr;
            }
        } else {
            // val <= 0: remove and delete cell
            if (prev) prev->next = curr->next;
            else        head       = curr->next;
            delete curr;
        }
        return;
    }

    // 2) Not found, only insert if val > 0
    if (val > 0) {
        // Create new cell
        Cell* newNode = new Cell{ key, val, nullptr };
        // Find insertion point
        Cell* p = nullptr;
        Cell* q = head;
        while (q && q->val >= val) {
            p = q;
            q = q->next;
        }
        if (!p) {
            // Insert at head
            newNode->next = head;
            head          = newNode;
        } else {
            newNode->next = q;
            p->next       = newNode;
        }
    }
    // If val <= 0 and key not present: do nothing
}


//Exercise 2
int PriorityQueue::get_max() const {
  
  return 0;
}

//Exercise 2
bool PriorityQueue::pop_max() {
    
  return false;
}

//Exercise 3
PriorityQueue PriorityQueue::operator+(const PriorityQueue& m) const {

  PriorityQueue res;
  return res;
}

//Exercise 3
PriorityQueue& PriorityQueue::operator=(const PriorityQueue& m) {
  return *this;
}
//Do not modify
void read_input(PriorityQueue& m) {
   int entries;
   cin>>entries;
   for (int i=0; i<entries; i++) {
     int key, val;
     cin>>key;
     cin>>val;
     m.insert(key,val);
   }
}

int main() {
  PriorityQueue a;
  read_input(a);
  a.print_list();
  return 0;
}