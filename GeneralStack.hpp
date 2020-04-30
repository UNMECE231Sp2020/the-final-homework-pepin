#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _values;
		size_t _size;
		
	public:
		//Default constructor
		Stack(){
			_size = 0;
		}

		//Default copy constructor
		Stack(const Stack &s){
			_values = s._values;
			_size = _values.size();
		}

		//Getters
		T top() const{
			return _values.front(){
			}

		size_t size() const{
			return _size;
		}

		//Adding data to the data structure
		void push(T value){
			_values.push_front(value);
		}

		//Removing data from the data structure
		void pop(){
			_values.pop_front();
		}

		bool search(Data value) {
			return (_values.search(value));
		}

		bool empty() const{
			return (_values.empty());
		}

		void print(){
			_values.print();
		}

		//This overloaded operator is empty, please implement
		Stack<T> operator=(const Stack<T> &s) {
			T _values=s._values(){
				_size=_values.size();
				return *this;
		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &s);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};

template <class S>
std::ostream &operator<< (std::ostream &out, const Stack<S> &s){
	out<<s._values;
}

template <class S>
bool operator==(const Stack<S> &left_side, const Stack<S> &right_side){
	if(left_side._values != right_side._values){
		return false;
	}
	else {
		return true;
	}
}
template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side){
	return !(left_side._values==right_side._values);
}

