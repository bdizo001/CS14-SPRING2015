#include <iostream>
#include <forward_list>
#include <cassert>
using namespace std;

template<typename T>
//typedef int T;
struct Node{
	T value;
	Node *next;
	Node(char value) : value(value), next(0) {}
};

template<typename T>
//typedef int T;
class List{
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        List() : head(0), tail(0) {}
        List<T> elementSwap(List<T> lst, int pos);
        int size() const{
            int i = 0;
            for(Node<T> *temp = head; temp != 0; temp = temp->next){
                ++i;
            }
            return i;
        }
        void push_back(T value){
    	    //add a node containing value to the end of the list
        	Node<T> *temp = new Node<T>(value); //new item, next already points to 0
        	if(tail != 0){
        		tail->next = temp; //previous tail gets replaced
        	}
        	tail = temp;
        	if(head == 0){//check if list is empty
        		head = tail;
    	    }
        }
        
        void print() const{
            for(Node<T> *temp = head; temp != 0; temp = temp->next){
                cout << temp->value << ' ';
            }
        }

};

template<typename T>
//typedef int T;
List<T> List<T>::elementSwap(List<T> lst, int pos){
    assert(pos + 2 < lst.size());
    assert(pos >= 0);
    
    if(pos == 0){
        Node<T> *temp = head->next;
        if(tail == temp){
            tail = head;
        }
        head->next = temp->next;
        temp->next = head;
        head = temp;
    }
    else{
        Node<T> *temp = head;
        for(int i = 0; i < pos - 1; ++i){
            temp = temp->next;       
        }
        Node<T> *temp1 = temp->next;
        Node<T> *temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp1;
        temp->next = temp2;
    }    
    return lst;
    
}