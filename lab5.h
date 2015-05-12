//lab 5
//name: Brian Dizon
//SID: 861140364
//Date: May 5, 2015
//***NOTE TO GRADER: Code for lab5 functions starts on line 361
	//all else is code from previous assignment 

// -*- bst.h -*-
#ifndef LAB5_H
#define LAB5_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0
// #define Value int // restore for testing.
template < typename Value >
class BST {
		class Node { // binary tree node
			public:
				Node* left;
				Node* right;
				Value value;
				bool selected;
				Node( const Value v = Value() )
				: left(nil), right(nil), value(v), selected(false)
				{}
				Value& content() { return value; }
				bool isInternal() { return left != nil && right != nil; }
				bool isExternal() { return left != nil || right != nil; }
				bool isLeaf() { return left == nil && right == nil; }
				int height(){
					if(this == NULL){
						return 0;
					}
					else if(!left && !right){
						return 0;
					}
					else if(!left && right){
						return right->height() + 1;
					}
					else if(left && !right){
						return left->height() + 1;
					}
					else{
						int leftHeight = left->height() + 1;
						int rightHeight = right->height() + 1;
						
						return leftHeight > rightHeight ? leftHeight : rightHeight;
						
					}}
				int size() {
					// returns the size of the subtree rooted at this node,
					if(this == NULL){
						return 0;
					}
					else if(isLeaf()){
						return 1;
					}
					else if(!left && right){ //only has right children
						return right->size() + 1;
					}
					else if(left && !right){ //only has left children
						return left->size() + 1;
					}
					else{	//has children on both sides
						return left->size() + right->size() + 1;
					}
				}
				
				void preorder(){
					if(!left && !right){
						cout << value << endl;
					}
					else if(!left && right){
						cout << value << endl;
						right->preorder();
					}
					else if(left && !right){
						cout << value << endl;
						left->preorder();
					}
					else{
						cout << value << endl; //print_node(root)
						left->preorder();
						right->preorder();
					}
				}
				void postorder()const {
					if(!left && !right){
						cout << value << endl;
					}
					else if(!left && right){
						right->postorder();
						cout << value << endl;
					}
					else if(left && !right){
						left->postorder();
						cout << value << endl;
					}
					else{
						left->postorder();
						right->postorder();
						cout << value << endl; //print_node(root)
					}
				}
				void inorder()const {
					// Traverse and print the tree one Value per line in inorder.
					if(!left && !right){
						cout << value << endl;
					}
					else if(!left && right){
						cout << value << endl;
						right->inorder();
					}
					else if(left && !right){
						left->inorder();
						cout << value << endl;
					}
					else{
						left->inorder();
						cout << value << endl; //print_node(root)
						right->inorder();
					}
				}
				bool search(Value x){
					if(value == x){
						return true;
					}
					if(!left && !right){}
					else if(!left && right){
						if(right->search(x)){
							return true;
						}
						return false;
					}
					else if(left && !right){
						if(left->search(x)){
							return true;
						}
						return false;
					}
					else{
						if(left->search(x)){return true;}
						if(right->search(x)){return true;}
						return false;
					}
					return false;
				}
				
				void traverseHelper(Node* n, int counter){
					
				}
		}; 	// Node
		// const Node* nil; // later nil will point to a sentinel node.
		Node* root;
		int count;
	public:
		int size() {/*WORKING*/
		// size of the overall tree.
			if(root == NULL){
				return 0;
			}
			else if(!root->left && !root->right){
				return 1;
			}
			return root->size();
		}
		bool empty() { return size() == 0; }
		void print_node( const Node* n ) {/*FILLED*/
			// Print the node’s value.
			if(n != NULL){
				cout << n->value << endl;
			}
		}
		bool search ( Value x ) {/*FILLED*/
			// search for a Value in the BST and return true iff it was found.
			if(root == NULL){
				return false;
			}
			
			if(root->content() == x){
				return true;
			}
			if(!left && !right){}
			else if(!left && right){
				if(root->right->search(x)){
					return true;
				}
				return false;
			}
			else if(left && !right){
				if(root->left->search(x)){
					return true;
				}
				return false;
			}
			else{
				if(root->left->search(x)){	return true;}
				if(root->right->search(x)){ return true;}
				return false;
			}
			
			return false;
		}
		void preorder()const {
			// Traverse and print the tree one Value per line in preorder.
			if(!root){
				return;
			}
			if(root->isLeaf()){
				cout << root->content() << endl;
			}
			if(!root->isLeaf()){
				if(!left && right){//no left child
					cout << root->content() << endl;
					root->right->preorder();
				}
				else if(left && !right){//no right child
					cout << root->content() << endl; //print_node(root)
					root->left->preorder();
				}
				else{//both children present
					cout << root->content() << endl; //print_node(root)
					root->left->preorder();
					root->right->preorder();
				}
			}
			
		}
		void postorder()const {
			// Traverse and print the tree one Value per line in postorder.
			if(!root){
				return;
			}
			if(root->isLeaf()){
				cout << root->content() << endl;
			}
			if(!root->isLeaf()){
				if(!left && right){
					root->right->postorder();
					cout << root->content() << endl;
				}
				else if(left && !right){
					root->left->postorder();
					cout << root->content() << endl;
				}
				else{
					root->left->postorder();
					root->right->postorder();
					cout << root->content() << endl; //print_node(root)
				}
			}
		}
		void inorder()const {
			// Traverse and print the tree one Value per line in inorder.
			if(!root){
				return;
			}
			if(root->isLeaf()){
				cout << root->content() << endl;
			}
			if(!root->isLeaf()){
				if(!left && right){
					cout << root->content() << endl;
					root->right->inorder();
				}
				else if(left && !right){
					root->left->inorder();
					cout << root->content() << endl;
				}
				else{	
					root->left->inorder();
					cout << root->content() << endl; //print_node(root)
					root->right->inorder();
				}
			}
		}
		Value& operator[] (int n) {/*fillin*/
			// returns reference to the value field of the n-th Node in order
			if(n == 0){
				return root->value;
			}
			
			Node* temp = root;
			traverseHelper(temp, n);
			return temp->value;
		}
		BST() : root(nil)/*, count(0) */{}
		void insert( Value X ) { root = insert( X, root ); }
		Node* insert( Value X, Node* T ) {
			// The normal binary-tree insertion procedure ...
			if ( T == nil ) {
				T = new Node( X ); // the only place that T gets updated.
			} 
			else if ( X < T->value ) {
				T->left = insert( X, T->left );
			} 
			else if ( X > T->value ) {
				T->right = insert( X, T->right );
			} 
			else {
				T->value = X;
			}
			// later, rebalancing code will be installed here
			return T;
		}
		void remove( Value X ){
			root = remove( X, root );
		}
		Node* remove( Value X, Node*& T ) {
			// The normal binary-tree removal procedure ...
			// Weiss’s code is faster but way more intricate.
			if ( T != nil ) {
				if ( X > T->value ) {
					T->right = remove( X, T->right );
				} 
				else if ( X < T->value ) {
					T->left = remove( X, T->left );
				} 
				else { // X == T->value
					if ( T->right != nil ) {
						Node* x = T->right;
						while ( x->left != nil ) x = x->left;
						T->value = x->value; // successor’s value
						T->right = remove( T->value, T->right );
					} 
					else if ( T->left != nil ) {
						Node* x = T->left;
						while ( x->right != nil ) x = x->right;
						T->value = x->value; // predecessor’s value
						T->left = remove( T->value, T->left );
					} 
					else { // *T is external
						delete T;
						T = nil; // the only updating of T
					}
				}
			}
			// later, rebalancing code will be installed here
			return T;
		}
		void okay(){ 
			okay( root ); 
		}
		void okay(Node* T){
			// diagnostic code can be installed here
			return;
		}
		Node* getRoot() const{
			return root;
		}
		
	
//--------------------------START LAB 5 CODE---------------------------------
	

        // EXERCISE 1
		 
		void minCover(){
		    minCoverHelper(root, 0);
		}
		 
		void minCoverHelper(Node* n, int i){
		    if(n != root && (n->left != nil) && (n->left->left == nil || n->left->right == nil)){
		        n->selected = true;
		        i = 0;
		    }
		    else if(n != root && (n->right != nil) && (n->right->right == nil || n->right->right == nil)){
		        n->selected = true;\
		        i = 0;
		    }
		    else if(n != root && i == 1){
		        n->selected = true;
		        i = 0;
		    }
		    else{
		        i = 1;
		    }
		   
		    if(n->left != nil){
		        minCoverHelper(n->left, i);
		    }
		   
		    if(n->right != nil){
		        minCoverHelper(n->right, i);
		    }
		}
		 
		void displayMinCover(){
		    count = 0;
		    displayMinCoverHelper(root);
		    cout << endl << count << endl;
		}
		 
		void displayMinCoverHelper(Node* n){
		    if(n->left != nil)
		    {
		        displayMinCoverHelper(n->left);
		    }
		   
		    if(n->selected)
		    {
		        cout << n->value <<  ' ';
		        count++;
		    }
		   
		    if(n->right != nil)
		    {
		        displayMinCoverHelper(n->right);
		    }
		}
		 
		// EXERCISE 2
		 
		void findSumPath(Node* n, int sum, int buffer[]){
		    count = 0;
		    bool check = false;
		    findSumPathHelper(n, buffer, sum, 0, check);
		    if(!check){
		        cout << '0' << endl;
		    }
		   
		    count = 0;
		}
		 
		void findSumPathHelper(Node* n, int* a, int sum, int len, bool& check){
		    if(n == 0){
		        return;
		    }
		   
		    a[len] = n->value;
		    len++;
		   
		    if (n->left == nil && n->right == nil){
		        printPath(a, len, sum, check);
		    }
		   
		    findSumPathHelper(n->left, a, sum, len, check);
		    findSumPathHelper(n->right, a, sum, len, check);
		}
		 
		void printPath(int* a, int len, int sum, bool& check){
		    int pSum = 0;
		    for(int i = 0; i < len; i++){
		        pSum += a[i];
		    }
		    if(pSum == sum){
		        check = true;
		        for(int i = len - 1; i > -1; i--){
		            cout << a[i] << ' ';
		        }
		        cout << endl;
		    }
		}
		 
		// EXERCISE 3
		void vertSum(Node* node, int hd, map<int, int>& m){
		    vertSumHelper(node, hd, m);
		   
		    for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
		        cout << it->second << ' ';
		    }
		}
		 
		void vertSumHelper(Node* node, int hd, map<int,int>& m){
		    if(node->left != nil){
		        int tempL = hd - 1;
		        vertSumHelper(node->left, tempL, m);
		    }
		 
		    m[hd] += node->value;
		   
		    if(node->right != nil){
		        int tempR = hd + 1;
		        vertSumHelper(node->right, tempR, m);
		    }
		}
		
}; // BST
#endif