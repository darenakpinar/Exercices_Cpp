#include <iostream>


public:
	struct iterator{
		// a tag for the standard library:
		// can be accessed through lis<Val>::iterator::iterator_category
		// the stl uses this tag to understand which algorithm to use
		using iterator_caregory = std::forward_siterator_tag;
		//listMVal>::iterator ::value_type x;
		using value_type = Val;
		using pointer = Val*;
		using regerence = Val&;

		//in other words: my iterator is just a shallow copt of a node
		iterator(node*); // this will used only by the lis<Val>


		//we do not need destructor and copy/move semantics
		//only need these if you allocate memory in your class

		//first return (old value), then increment
		iterator& operator++(); //pre-increment: ++it

		//furst return (old value), then increment. This is implemented as:
		// make a copt it1 of *this
		//inrement *this
		//return it1
		iterator operator++(int);//post-incremen: x= ( it++)

		//exhibits pointers to the inner values (allows using sintax ->)
		pointer operator->() const;

		//this allow me to do *it
		reference operator*() const;

		//it1== it2
		bool operator == (iterator const&)const;
		bool operator != (iterator const&)const;

		//always true except when we reach one past the end of the 
		// container (false onlt for list<Val>
		operator bool()const;

		//node * x;
		//x->cal; x->next

		//list<Val>::iterator it; 
private:
	node* m_ptr;

};

	iterator begin();
	iterator end();// iterator  to one element past the end of list (not to the last element

	//next lecture: we meed to define an iterator class pinting to const Cal, to be
	// able to compile code like this:
	//const
