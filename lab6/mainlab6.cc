#include "selectionsort.h"
#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;

void vectorDisplay(const vector<int> &v){
    for(unsigned i = 0; i < v.size(); ++i){
        cout << v.at(i) << ' ';
    }
    cout << endl;
}

void vectorPairDisplay(const vector< pair<int, int> > &v){
    for(unsigned i = 0; i < v.size(); ++i){
        cout << "(" << v.at(i).first << ", " << v.at(i).second << ") ";
    }
    cout << endl;
}

void listDisplay(const list<int> &l){
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;
}

void listPairDisplay(const list< pair<int, int> > &l){
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << "(" << it->first << ", " << it->second << "), ";
    }
    cout << endl;
}

int main(){
    cout << "Testing for vector of integers: " << endl;
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    
    cout << "Pre sort: "; vectorDisplay(v);
    selectionsort(v);
    cout << "Post sort: "; vectorDisplay(v);
    cout << endl;
    ////////////////////////////////////////////////////////
    cout << "Testing for vector of pair<int, int>: " << endl;
    vector< pair<int, int> > vp;
    vp.push_back(pair<int, int>(1,2));
    vp.push_back(pair<int, int>(3,-1));
    vp.push_back(pair<int, int>(-1,3));
    vp.push_back(pair<int, int>(0,0));
    vp.push_back(pair<int, int>(2,3));
    vp.push_back(pair<int, int>(1,2));
    vp.push_back(pair<int, int>(1,-2));
    vp.push_back(pair<int, int>(8,10));
    
    cout << "Pre sort: "; vectorPairDisplay(vp);
    selectionsort(vp);
    cout << "Post sort: "; vectorPairDisplay(vp);
    cout << endl;
    ////////////////////////////////////////////////////////////
    cout << "Testing for list of integers: " << endl;
    list<int> l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);
    l.push_back(1);
    l.push_back(8);
    l.push_back(9);
    
    cout << "Pre sort: "; listDisplay(l);
    selectionsort(l);
    cout << "Post sort: "; listDisplay(l);
    cout << endl;
    /////////////////////////////////////////////////////////////
    cout << "Testing for list of pair<int, int>: " << endl;
    list< pair<int, int> > lp1;
    lp1.push_back(pair<int, int>(1,2));
    lp1.push_back(pair<int, int>(3,-1));
    lp1.push_back(pair<int, int>(-1,3));
    lp1.push_back(pair<int, int>(0,0));
    lp1.push_back(pair<int, int>(2,3));
    lp1.push_back(pair<int, int>(1,2));
    lp1.push_back(pair<int, int>(1,-2));
    lp1.push_back(pair<int, int>(8,10));
    
    cout << "Pre sort: "; listPairDisplay(lp1);
    selectionsort(lp1);
    cout << "Post sort: "; listPairDisplay(lp1);
    cout << endl;
    /////////////////////////////////////////////////////////////
    cout << "Testing for list of pair<int, int>: " << endl;
    list< pair<int, int> > lp2;
    lp2.push_back(pair<int, int>(10,2));
    lp2.push_back(pair<int, int>(-3,-1));
    lp2.push_back(pair<int, int>(-8,0));
    lp2.push_back(pair<int, int>(1,1));
    lp2.push_back(pair<int, int>(1,1));
    lp2.push_back(pair<int, int>(0,0));
    lp2.push_back(pair<int, int>(10,2));
    lp2.push_back(pair<int, int>(5,5));
    lp2.push_back(pair<int, int>(5,-5));
    lp2.push_back(pair<int, int>(0,0));
    lp2.push_back(pair<int, int>(10,2));
    
    cout << "Pre sort: "; listPairDisplay(lp2);
    selectionsort(lp2);
    cout << "Post sort: "; listPairDisplay(lp2);
    cout << endl;
    //////////////////////////////////////////////////////////////
    cout << "Testing for list of pair<int, int>: " << endl;
    list< pair<int, int> > lp3;
    lp3.push_back(pair<int, int>(-1,3));
    lp3.push_back(pair<int, int>(0,0));
    lp3.push_back(pair<int, int>(1,-2));
    lp3.push_back(pair<int, int>(1,2));
    lp3.push_back(pair<int, int>(1,2));
    lp3.push_back(pair<int, int>(2,3));
    lp3.push_back(pair<int, int>(3,-1));
    lp3.push_back(pair<int, int>(8,10));
    
    cout << "Pre sort: "; listPairDisplay(lp3);
    selectionsort(lp3);
    cout << "Post sort: "; listPairDisplay(lp3);
    ////////////////////////////////////////////////////////////
    cout << "Testing for stability: " << endl;
    vector<int> v2 = {1,1,1,1,1,1,1,1};
    cout << "Pre sort: "; vectorDisplay(v2);
    selectionsort(v2);
    cout << "Post sort: "; vectorDisplay(v2);
    cout << "If number of moves == 0, then the function is stable" << endl;
    return 0;
}