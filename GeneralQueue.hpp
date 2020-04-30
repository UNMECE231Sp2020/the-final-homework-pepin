#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class QueueClass>
class Queue {
	private:
		List<QueueClass> _values;
		size_t _size;
	public:
		//Default constructor
		Queue(){
			_size = 0;
		}

		//Copy constructor
		Queue(const Queue<QueueClass> &q){
			_values q._values;
			_size = _values.size();
		} 

		//Getters
		size_t size() const{
			return _size;

		QueueClass front() const{
			return _values.front();
		}

		QueueClass back() const{
			return _values.back();
		}

		//Push to queue
		void enqueue(QueueClass value){
			_values.push_back(value);
		}

		//Pop from queue
		void dequeue(){
			_values.pop_front();
		}

		void print(){
			_values.print();
		}

		bool search(QueueClass value){
			return _values.search(value);
		}

		bool empty() const{
			return (_values.empty());
		}

		Queue<QueueClass> &operator=(const Queue<QueueClass> q) {
			_values = q._values;
			_size = _values.size();
			return *this;
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};
template <class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &q){
	out << q.values;
}

template <class U>
bool operator==(const Queue<U> &left_side, const Queue<U> &right_side){
	if(left_side._values != right_side._values){
		return false;
	}
	else{
		return true;
	}
}

template <class U>
bool operator!=(const Queue<U> &left_side, const Queue<U> &right_side){
	return !(left_side==right_side);
}

