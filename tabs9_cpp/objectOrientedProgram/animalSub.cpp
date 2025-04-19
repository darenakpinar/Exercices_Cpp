#include <iostream>
using namespace std;

class Animal{
protected:
	string name;

public:
	Animal(string n){
		name = n;
		cout << name << "the Animal is created!" << endl;
 	}
	virtual void speak(){
		cout << name << "makes a sound!" << endl;
	}
	
};

class Dog : public Animal{
public:
	
	Dog(string n) : Animal(n){
		cout << name << "is a Dog." << endl;
	}
	
	void speak(){
		cout << name << "says: Woof!" << endl;
	}
	
};

class Cat : public Animal {
public: 
	Cat(string n) : Animal(n){
		cout << name << "is a Cat." << endl;
	}
	
	virtual void speak(){
		cout << name << "says: Meaw!" << endl;
	}
	
};

int main(){
	Animal* a1 = new Dog("Moka");
	Animal* a2 = new Cat("Sasa");

	a1->speak();
	a2->speak();
	
	delete a1;
	delete a2;

	return 0;
}


