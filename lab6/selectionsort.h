//lab 6
//Name: Brian Dizon
//SID: 861140364
//Date: May 12, 2015

#ifndef LAB6_H
#define LAB6_H
#include <iostream>
#include <utility>
using namespace std;


template<typename L>        //L represents any list container w/ iterators
void selectionsort(L &l){
    //use iterators and swap to implement select sort algorithm
    int moves = 0;
    int copies = 0;
    
    for(auto it = l.begin(); it != l.end(); ++it){
        auto start = it;
        ++start;
        auto temp = it;
        
        for(; start != l.end(); ++start){
            if(*it > *start){
                temp = start;
            }
        }
        
        if(it != temp){
            swap(*it, *temp);
            moves += 3;
        }
    }
    
    cout << "Copies: " << copies << endl;
    cout << "Moves: " << moves << endl;
    
    return;
}

#endif