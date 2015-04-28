#include "lab2.h"
#include <iostream>
#include <forward_list>
using namespace std;


bool isPrime(int i){
    bool prime = true;
    if(i == 0 || i == 1){
        prime = false;
    }
    for(int k = 2; k < i; ++k){
        if(i % k == 0){ //if i is divisible by any number, not prime
            prime = false;
        }
    }
    return prime;
}

int primeCount(forward_list<int> lst){
    if(lst.empty()){ //base case
        return 0; //empty list has no (prime) numbers
    }
    if(isPrime(lst.front())){ //check if first item is prime
        cout << lst.front() << endl;
        lst.pop_front(); //can do this bc lst is passed by value
        return 1 + primeCount(lst); //recursive call
    }
    else{ //first number isnt prime
        lst.pop_front(); //dont output, just delete it
        return primeCount(lst); //dont add 1 to primecount
    }
}

//template<typename T>
typedef int T;
forward_list<T> listCopy(forward_list<T> L, forward_list<T> &P){
    //concatenate L - in reverse - to the back of P
    forward_list<T> temp;
    while(!L.empty()){
        temp.push_front(L.front());
        L.pop_front();
    }
    
    P.reverse();
    while(!P.empty()){
        temp.push_front(P.front());
        P.pop_front();
    }
    
    P = temp;
    return P;   
}

//template<typename T>
typedef int T;
void printLots(forward_list<T> L, forward_list<int> P){
    int temp = 0;
    while(!P.empty()){
        int pos = P.front() - temp;
        temp = pos;
        for(; pos > 0; --pos){
            L.pop_front();
        }
        cout << L.front() << " ";
        P.pop_front();
    }
    //keep L.pop_front() until you get to the right position
    
    return;
}

int main(){
    forward_list<int> l1 = {1,2,3,4};
    forward_list<int> l2 = {0,3};
    printLots(l1, l2);
    
    return 0;
}