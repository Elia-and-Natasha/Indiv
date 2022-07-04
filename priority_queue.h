#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <sstream>
class Error {};

template <typename T>
class priority_queue{
private:
    struct Node
    {
        T data;
        Node* next;
        int priority;
        Node(T data, Node* next, int p) {
            this->data = data;
            this->next = next;
            priority = p;
        }

        friend 	ostream& operator<< (ostream& out, const Node& X) {
            out << X.data;
            return out;
        }
    } *head;
public:

    // конструктор по умолчанию
    priority_queue() {
        head = nullptr;
    }
	// деструктор
	~priority_queue() {
		while (head) {
			Node* cur = head;
			head = head->next;
			delete cur;
		}
		head = nullptr;
	}
	priority_queue(const priority_queue& other):priority_queue() {
		
		if (other.head) {
			Node* cur = other.head;
			while (cur) {
				this->push(cur->data, cur->priority);
				cur = cur->next;
			}
		}
	}
	


	// добавление
	//1) первыми вставляются элементы с минимальным priority
    void push(T val, int p) {
        //пустой

        if (head == nullptr)
            head = new Node(val, nullptr, p);


        else {
			// вставить первым
            Node* cur = head;
			if (cur->priority > p) {
				head = new Node(val, head, p);
			}
			// после 1ого
			else {
				while (cur->next != nullptr && cur->next->priority <= p && cur->priority <= p) {
					cur = cur->next;
				}
				cur->next = new Node(val, cur->next, p);
				
			}
        }
    }
	//2) первыми вставляются элементы с максимальным priority
	void push_back(T val, int p) {
		//пустой

		if (head == nullptr)
			head = new Node(val, nullptr, p);


		else {
			// вставить первым
			Node* cur = head;
			if (cur->priority < p) {
				head = new Node(val, head, p);

			}
			// после 1ого
			else {
				while (cur->next != nullptr && cur->next->priority >= p && cur->priority >= p) {
					cur = cur->next;
				}
				cur->next = new Node(val, cur->next, p);

			}
		}
	}


	//получение значения очередного элемента
	T get_first()
	{
		if (head) 
			return head->data;
		else
			throw "Queue is empty";

	}
	//извлечение
	T top()
	{
		if (head)
		{
			T x = head->data;
			Node* t = head;
			head = head->next;
			delete t;

			if (!head)
			{
				head = nullptr;
			}
			return x;
		}
		else throw "Queue is empty";
	}

	// вывод в поток.
	void print() {
		if (head) {
			Node* cur = head;
			while (cur) {
				cout << *cur << " "; cur = cur->next;
				cout << endl;
			}
			cout << endl;
		}
		else throw "Queue is empty";
	}
	priority_queue& input() {
		int size;
		cout << "Size: " << endl;
		cin >> size;
		T elem;
		int pp;

		int i= 0;
		while (i < size) {
			cout << "Element: ";
			cin >> elem;
			cout << "priority: ";
			if (cin >> pp) {
				this->push(elem, pp);
				i++;
			}
			else {
				throw "priority must be integer";
			}
			
		}
		return *this;
	
	
	}
	 

	int size_queue() {
		int i = 0;
		Node* cur = head;
		while (cur) { i++; cur = cur->next; }
		return i;
	}
	bool operator==( priority_queue& a)
	{
		if (this->size_queue() == a.size_queue()) {
			Node* cur1 = head;
			Node* cur2 = a.head;
			while (cur1) {
				if (cur1->data != cur2->data) return false;
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return true;
		}
		else return false;

	}

	//оператор присваивания
	priority_queue& operator=(const priority_queue& a)
	{
		while (!this->isEmpty()) {
			this->top();
		}
		if (a.head) {
			Node* tmp = a.head;
			while (tmp) {
				this->push(tmp->data, tmp->priority);
				tmp = tmp->next;
			}
			return *this;
		}
		else return *this;
	}
	//слияние очередей
	priority_queue& operator+(priority_queue& other) {
		priority_queue<int>* res = new priority_queue;
		Node* cur1 = head;
		Node* cur2 = other.head;

		while (cur1) {
			res->push(cur1->data, cur1->priority);
			cur1 = cur1->next;

		}
		while (cur2) {
			res->push(cur2->data, cur2->priority);
			cur2 = cur2->next;

		}
		
		return *res;
	}
	//извлечение из очереди
	friend ostream& operator << (ostream& os, priority_queue& q) {
		if (q.head) {
			os << q.top() << endl;

			return os;
		}
		else throw "Empty";
	}
	//добавление элемента в очередь;
	friend istream& operator >> (istream& is, priority_queue& q) {
		T elem;
		int pp;
		cout << "Element: ";
		is >> elem;
		cout << endl << "Priority: ";
		if (is >> pp) {
			q.push(elem, pp);
			return is;
		}
		else {
			throw "priority must be integer";
		}
	}

	//проверка очереди на пустоту;
    bool isEmpty() {
        return head == nullptr;
    }

	
};

