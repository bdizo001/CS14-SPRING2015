//lab 5
//name: Brian Dizon
//SID: 861140364
//Date: May 5, 2015


#include "lab5.h"
#include <iostream>
using namespace std;

int main(){
	BST<int> tree;
	
	
	//assn 3 test harnesses
// 	//insert is given
// 	cout << "Inserting 10 values" << endl;
// 	tree.insert(12);
// 	tree.insert(15);
// 	tree.insert(21);
// 	tree.insert(7);
// 	tree.insert(2);
// 	tree.insert(5);
// 	tree.insert(10);
// 	tree.insert(4);
// 	tree.insert(8);
// 	tree.insert(1);
	
// 	cout << "Size: " << tree.size() << endl;
	
// 	cout << "Height: " << tree.getRoot()->height() << endl;
	
// 	cout << "Testing: preorder()" << endl;
// 	tree.preorder();
// 	cout << endl;
	
// 	cout << "Testing: postorder()" << endl;
// 	tree.postorder();
// 	cout << endl;
	
// 	cout << "Testing: inorder()" << endl;
// 	tree.inorder();
// 	cout << endl;
	
// 	cout << "Root value: ";
// 	tree.print_node(tree.getRoot());
// 	cout << endl;
	
// 	cout << "Test [] operator" << endl;
// 	cout << "not yet implemented" << endl << endl;
	
//     cout << "Search for 4: ";
//     if(tree.search(4))
//     {
//         cout << "Found" << endl;
//     }
//     else
//     {
//         cout << "Not Found" << endl;
//     }
//     cout << "Search for 10: ";
//     if(tree.search(10))
//     {
//         cout << "Found" << endl;
//     }
//     else
//     {
//         cout << "Not Found" << endl;
//     }
//     cout << "Search for 1: ";
//     if(tree.search(1))
//     {
//         cout << "Found" << endl;
//     }
//     else
//     {
//         cout << "Not Found" << endl;
//     }

//recreate tree from specs
    tree.insert(50);
    tree.insert(20);
	tree.insert(10);
	tree.insert(40);
	tree.insert(35);
	tree.insert(45);
	tree.insert(60);
	tree.insert(70);
	
	
//test exercise 1
	tree.minCover();
	tree.displayMinCover();
	
//test exercise 2
	int buffer[100];
	tree.findSumPath(tree.getRoot(), 80, buffer);
	
//test exercise 3
	map<int, int> m;
	tree.vertSum(tree.getRoot(), 0, m);
	
	
	return 0;
}