#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

//helper function
void preOrderHelper(int m, int n, int k){
    if(n + m > k){
        return;
    }
    
    cout << m << ' ' << n << endl;
    
    preOrderHelper(2 * m - n, m, k);
    preOrderHelper(2 * m + n, m, k);
    preOrderHelper(m + 2 * n, n, k);
    
    return;
}

void preOrderPrint(int k){
    preOrderHelper(2, 1, k);
    preOrderHelper(3, 1, k);
}

//////////////////////////////////////

void postOrderHelper(int m, int n, int k){
    if(m + n > k){
        return;
    }
    
    postOrderHelper(2 * m - n, m, k);
    postOrderHelper(2 * m + n, m, k);
    postOrderHelper(m + 2 * n, n, k);

    cout << m << ' ' << n << endl;
    
    return;
}

void postOrderPrint(int k){
    postOrderHelper(2, 1, k);
    postOrderHelper(3, 1, k);
}

/////////////////////////////////////

void inOrderHelper(int m, int n, int k, priority_queue<pair<int, pair<int, int> > > &q)
{
    if((m+n) >= k)
    {
        return;
    }
   
    q.push(pair<int, pair<int, int> > (m + n, pair<int,int> (m, n)));
   
    inOrderHelper(2 * m - n, m, k, q);
    inOrderHelper(2 * m + n, m, k, q);
    inOrderHelper(m + 2 * n, n, k, q);
}

void inOrderPrint(int k)
{
    priority_queue<pair<int, pair<int,int> > > q;
   
    inOrderHelper(2, 1, k, q);
    inOrderHelper(3, 1, k, q);
   
    stack< pair<int,int> > s;
   
    while(!q.empty())
    {
        s.push(q.top().second);
        q.pop();
    }
   
    while(!s.empty())
    {
        cout << s.top().first << ' ' << s.top().second << endl;
        s.pop();
    }
}

#endif