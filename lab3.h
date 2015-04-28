/*
Name:   Brian Dizon
SID:    861140364
Date:   April 21, 2015
*/
#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

template<typename T>
class TwoStackFixed{
    private:
        T* arr;
        int size;   //size of array
        int maxtop; //first element of stack 2
        int loc1;   //current loc of stack 1
        int loc2;   //current loc of stack 2
    public:
        void display(){
            for(int i = 0; i < loc1 + 1; ++i){
                cout << arr[i] << ' ';
            }
            // for(int i = loc1 + 1; i < loc2; ++i){
            //     cout << " "
            // }
            for(int i = loc2; i < size; ++i){
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        
        TwoStackFixed(int size, int maxtop ){
            this->size = size;
            this->maxtop = maxtop;
            assert(!maxtop * 2 <= size);
            arr = new T[size];
            loc1 = - 1;
            loc2 = size;
        }
        
        ~TwoStackFixed(){
            delete[] arr;
        }
        
        void pushStack1(T value){
            assert(!isFullStack1());    //if stack is already full -> error
            loc1++;
            arr[loc1] = value;
            
            //display();
        }
        
        void pushStack2(T value){
            assert(!isFullStack2());    //if full, error
            loc2--;        
            arr[loc2] = value;
            
            //display();
        }
        
        T popStack1(){
            assert(!isEmptyStack1());   //if empty, nothing to pop
            T temp = arr[loc1];
            loc1--;
            return temp;
        }
        
        T popStack2(){
            assert(!isEmptyStack2());
            T temp = arr[loc2];
            loc2--;
            return temp;
        }
        
        bool isFullStack1(){
            if(loc1 == maxtop - 1){
                return true;
            }
            return false;
        }
        
        bool isFullStack2(){
            if(loc2 == maxtop){
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1(){
            if(loc1 == -1){
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2(){
            if(loc2 == size){
                return true;
            }
            return false;
        }
};

template<typename T>
class TwoStackOptimal{ //not even done
    private:
        T* arr;
        int size;
        int loc1;
        int loc2;
    public:
        void display(){
            for(int i = 0; i < loc1 + 1; ++i){
                cout << arr[i] << ' ';
            }
            // for(int i = loc1 + 1; i < loc2; ++i){
            //     cout << ' ';
            // }
            for(int i = loc2; i < size; ++i){
                cout << arr[i] << ' ';
            }    
            cout << endl;
        }
        
    
        TwoStackOptimal(int size){
            this->size = size;
            arr = new T[size];
            loc1 = -1;
            loc2 = size;
        }
        ~TwoStackOptimal(){
            delete[] arr;
        }
        void pushFlexStack1(T value){
            assert(!isFullStack1());    //if full, error
            loc1++;
            arr[loc1] = value;
            
            //display();
        }
        
        void pushFlexStack2(T value){
            assert(!isFullStack2());
            loc2--;
            arr[loc2] = value;
            
            //display();
        }
        
        T popFlexStack1(){
            assert(!isEmptyStack1());
            T temp = arr[loc1];
            loc1--;
            return temp;
        }
        
        T popFlexStack2(){
            assert(!isEmptyStack2());
            T temp = arr[loc2];
            loc2++;
            return temp;
        }
        
        bool isFullStack1(){
            if(loc1 + 1 == loc2){
                return true;
            }
            return false;
        }
        
        bool isFullStack2(){
            if(loc2 - 1 == loc1){
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1(){
            if(loc1 == -1){
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2(){
            if(loc2 == size){
                return true;
            }
            return false;
        }
};

template<typename T>
void showTowerStates(int n, stack<T> &A, stack<T> &B, stack<T> &C,
const char x, const char y, const char z){
    //move top disks from A -> B
    //move 1 disk from A -> C
    //move top disks from B -> C
    
    if(n == 1){
        //move top of A to C
        C.push(A.top());
        A.pop();
    }
    else{
        showTowerStates(n-1, A, C, B, 'A', 'C', 'B');
        showTowerStates(1, A, B, C, 'A', 'B', 'C');
        showTowerStates(n-1, B, A, C, 'B', 'A', 'C');
    }
}    

template<typename T>
void showTowerStates(int n, stack<T> &A, stack<T> &B, stack<T> &C){
    assert(n > 0);
    showTowerStates(n, A, B, C, 'A', 'B', 'C');

}

template<typename T>
void display(stack<T> A, stack<T> B, stack<T> C){
    cout << "A: ";
    while(!A.empty()){
        cout << A.top() << ' ';
        A.pop();
    }
    cout << endl;
    
    cout << "Stack B: ";
    while(!B.empty()){
        cout << B.top() << ' ';
        B.pop();
    }
    cout << endl;
    
    cout << "Stack C: ";
    while(!C.empty()){
        cout << C.top() << ' ';
        C.pop();
    }
    cout << endl;
}

#endif