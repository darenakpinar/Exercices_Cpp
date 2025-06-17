#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class library_pool {
    // Design the internal struct/class and vector!
public:
    library_pool();
    ~library_pool();
    void add_book(int id, std::string title);
    void borrow_book(int id);
    void print_books() const;
    void print_top_k(unsigned int  k) const;
    int books_id(int pop)const;
    int books_borrow_count(int pop)const;
    string books_title(int pop)const;
private:
    // You design struct book, and vector<book>

    struct book{
        unsigned int id;
        unsigned int borrow_count;
        string title;
    }
    vector<book>v;


};

void library_pool::library_pool(){}
void library_pool::~library_pool(){}

int library_pool::books_id(int pop)const{
     return v[pop].id;
}
int library_pool::books_borrow_count(int pop)const{
    return v[pop].borrow_count;
}
string library_pool::books_title(int pop)const{
    return v[pop].title;
}


void library_pool::add_book(int id, std::string title){
    int i = 0;
    while (i < v.size() && v.at(i).borrow_count > 0 
    || (v.at(i).borrow_count == 0 && v.at(i).id < id))
        i++;

    book newBook{id, 0, title};
     v.push_back(book{0, 0, ""});

     for (int j=v.size()-1; j>i; j--)
        v.at(j)=v.at(j-1);

    v.at(i)=newBook;
    
}
void library_pool::borrow_book(int id){
    
    int i = 0;
    while (i<v.size() && v[i].id != id)i++;
    if (i == v.size())return; // not found
    v[i].borrow_count++;

    while (i > 0 && (v[i].borrow_count > v[i-1].borrow_count ||
    v[i].borrow_count== v[i-1] && v[i].id < v[i-1].id)){
        std::swap(v[i], v[i-1]);
        i--;
    }
}

void library_pool::print_books()const{
    int i = 0;
    int len = v.size();
    while (int i = 0; i < len; i++){
        cout << "book details: " << books_id(i) << books_borrow_count(i) << books_title(i) << endl;
    }
}
void library_pool::print_top_k(unsigned int val)const{
   k = (k > v.size()) ? v.size() : k;
   for (int i = 0; i < k; i++){
        cout << "book details: " << books_id(i) << books_borrow_count(i) << books_title(i) << endl;
   }
}


int main() {
    library_pool lib;
    int n; std::cin >> n;
    while (n--) {
        int id;
        std::string title;
        std::cin >> id >> title;
        lib.add_book(id, title);
    }
    lib.print_books();
    return 0;
}

// main function for exercise 2
int main() {
    library_pool lib;
    // ... read in all books as before ...
    int q;
    while (std::cin >> q && q > 0) {
        lib.borrow_book(q); // borrow book by ID
    }
    lib.print_books();
    return 0;
}

// main function for exercise 3
int main() {
    library_pool lib;
    // ... read in all books as before ...
    int k;
    std::cin >> k;
    lib.print_top_k(k); // print top k most borrowed books
    return 0;
}