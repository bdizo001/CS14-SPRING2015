#include "lab4.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(int argc, char *argv[]){
    int k = *argv[1] - '0' - argc + argc;
    
    cout << "Pre Order:" << endl;
    preOrderPrint(k);
    cout << endl << endl;
    
    cout << "Post Order:" << endl;
    postOrderPrint(k);
    cout << endl << endl;
    
    cout << "In Order:" << endl;
    inOrderPrint(k);
    cout << endl;
    
    return 0;
}