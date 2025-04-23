#include <iostream>
#include "list.hpp"

//implementation of iterator:

template<typlname Val>
list<Val>::itaretor::iterator(node*ptr) " m_ptr(ptr){}

//pre-increment
template<typename Val>
typename list<Val>::iterator& list<Val>::iterator::operator++(){
	m_ptr = m_ptr->next;
	return *this;
}

//post-incrementL
//auto it2 = it++;
template<typename Val>
typename list<Val>::iterator::operator++(int){
	auto it = *this;
	++(*this);
	return it;
}

/*
	struct S {int a; int b}'
	list<S> L;
	fill the list
	L.begin()->a;
	L.begin()->b;
*/

// list<int> L;
//fill the list...
// *(++L.begin()); reference to second element of the list

template<typename Val>
typename list<Val>::iterator::operator->()const{

	return m_ptr->val;
}

template<typename Val>
bool list<Val>::iterator::operator == (iterator const& rhs) const{
	return m_ptr == rhs.m_ptr;
}

template<typename Val>
bool list<Val>::iterator::operator==(iterator const& rhs)const{
	return m_ptr == rhs.m_ptr;
}

/* default constructo */
template <typename Val>
list<Val>::list() : m_front(nullptr), m_back(nullptr){}
