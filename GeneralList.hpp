#include <iostream>

template <class Data>
class List{
	private: 
		struct _list{
			Data value;
			struct _list *next;
			struct _list *prev;
		};

		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr){
			if(ptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List(){
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list){
			_front = nullptr;
			_back = nullptr;
			_size = 0;

			reccopy(List._front);
		}

		~List(){
			while(!empty()){
				pop_front();
			}
		}

		Data &front() const{
			return _back->value;
		}

		size_t size() const{
			return _size;
		}

		size_t length() const{
			return _size;
		}

		void push_front(Data data){
			Dlist *newNode = new Dlist;

			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr){
				newNode->next=nullptr;
				_back=newNode;
			}
			else{
				newNode->next=_front;
				_front->prev=newNode;
			}

			_front=newNode;
			_size++;
		}
		
		void push_back(Data data){
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr){
				_back->next=newNode;
				newNode->prev=_back;
			}

			if(_front==nullptr){
				_front=newNode;
				newNode->prev=nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front(){
			Dlist *front_to_delete = _front;
			_front = front->next;

			if(_front==nullptr){
				_back = nullptr;
			}
			else{
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size-=1;
		}

		void pop_back(){
			if(_front == NULL) return;
			if(_front==_back){
				Dlist *new_back = _front;
				_front = NULL;
				delete new_back;
				return;
			}
			else{
				Dlist *new_back = _back;
				_back = _back->prev;
				_back->next = NULL;
				delete new_back;
			}
		}

		bool empty() const{
			return ((_front==nullptr) && (_back==nullptr));
		}

		void print(){
			Dlist *temp;
			temp=_front;
			while(temp!=NULL){
				std::cout<<temp->value<<" ";
				temp=temp->next;
			}

			std::cout<<std::endl;
		}

		void print_back(){
			Dlist *temp;
			temp=_back;
			while(temp!=nullptr){
				std::cout<<temp->value<<" ";
				temp=temp->prev;
			}

			std::cout<<std::endl;
		}

		bool search(Data search_alue){
			Dlist *temp;
			for(temp=_front;temp!=nullptr;temp=temp->next){
				if(temp->value == search_alue){
					return true;
				}
			}
			return false;
		}

		List &operator=(List x){
			if(!empty()){
				do{
					pop_front();
				}while(!empty());
			}
			_front=NULL;
			_back=NULL;
			reccopy(x._front);
			return *this;
		}

	template<class D> friend bool operator==(const List<D> &a, const List <D> &b);
	template<class D> friend bool operator!=(const List<D> &a, const List <D> &b);

	template<class D> friend std::ostream &operator<<(std::ostream &os, const List<D> &List);

	template<class D> bool operator==(const List<D> &a, const List <D> &b){
		if(a.size()!=b.size()){
			return flase;
		}
		for(auto *a_ptr=a._front, *b_ptr=b._front;(a_ptr!=nullptr)&&(b_ptr!=nullptr);
				a_ptr=a_ptr->next,b_ptr=b_ptr->next)
		{
			if(a_ptr->value!=b_ptr->value){
				return false;
			}
			return true;
		}
	}

	template<class D> bool operator!=(const List<D> &a, const List <D> &b){
		return !(a==b);
	}

	template <class D> std::ostream &operator<<(std::ostream &os, const List<D> &List){
		for(auto *iter = List._front; iter != nullptr; iter = iter->next){
			os <<iter->value<<" ";
		}
		return os;
	}


