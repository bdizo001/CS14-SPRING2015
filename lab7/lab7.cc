#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <unordered_set>
using namespace std;


void setInsertion(unsigned n, vector<string> v, set<string> &s){
    //push first n words onto set
    for(unsigned i = 0; i < n; ++i){
        s.insert(v.at(i));
    }
}

void unorderedSetInsertion(unsigned n, vector<string> v, unordered_set<string> &s){
    for(unsigned i = 0; i < n; ++i){
        s.insert(v.at(i));
    }
}

void findSet(unsigned n, vector<string> v, set<string> &s){
    //find first n words in a set
    for(unsigned i = 0; i < n; ++i){
        s.find(v.at(i));
    }
}

void findUnorderedSet(unsigned n, vector<string> v, unordered_set<string> &s){
    for(unsigned i = 0; i < n; ++i){
        s.find(v.at(i));
    }
}

int main(){
    //create a vector of strings to hold words.txt
    vector<string> words;
    string word;
    ifstream fin;
    fin.open("words.txt");
    if(!fin.is_open()){
        cout << "Error: Cannot open words.txt" << endl;
        exit(1);
    }
    while(fin >> word){
        words.push_back(word);
    }
    fin.close();
    
    //used to hold the data
    ofstream fout;
    fout.open("data.txt");
    if(!fout.is_open()){
        cout << "Error: Cannot open data.txt" << endl;
    }
    
    for(int n = 5000; n <= 50000; n = n + 5000){
        cout << "Test " << n << endl;
        
        //SET INSERTION TIMES
        float avgSetInsertionTime = 0.0;
        //check insertion time everytime we insert
        for(int i = 0; i < 10; ++i){
            random_shuffle(words.begin(), words.end());
            
            set<string> s;
            clock_t t;
            t = clock();    //time immediately before insertion
            setInsertion(n, words, s);
            t = clock() - t; //end time - start time = change in time
            
            avgSetInsertionTime += t; //add onto the time
        }
        
        avgSetInsertionTime = avgSetInsertionTime / 10; //divide by number of runs
        avgSetInsertionTime = ((float)avgSetInsertionTime)/CLOCKS_PER_SEC;
        
        cout << "Average Set Insertion Time: " << avgSetInsertionTime << endl;
        
        
        
        //SET FIND TIMES
        set<string> s;
        setInsertion(50000, words, s);
        float avgSetFindTime = 0.0;
        //check find time each iteration
        for(int i = 0; i < 10; ++i){
            random_shuffle(words.begin(), words.end());
            clock_t t;
            t = clock();
            findSet(n, words, s);
            t = clock() - t;
            
            avgSetFindTime += t;
        }
        
        avgSetFindTime = avgSetFindTime / 10;
        avgSetFindTime = ((float)avgSetFindTime) / CLOCKS_PER_SEC;
        
        cout << "Average Set Find Time: " << avgSetFindTime << endl;
        
        
        //UNORDERED SET INSERTION TIMES
        float avgUnorderedSetInsertionTime = 0.0;
        //check insertion time each time we insert
        for(int i = 0; i < 10; ++i){
            random_shuffle(words.begin(), words.end());
            
            unordered_set<string> us;
            clock_t t;
            t = clock();
            unorderedSetInsertion(n, words, us);
            t = clock() - t;
            
            avgUnorderedSetInsertionTime += t;
        }
        
        avgUnorderedSetInsertionTime = avgUnorderedSetInsertionTime / 10;
        avgUnorderedSetInsertionTime = ((float)avgUnorderedSetInsertionTime)/CLOCKS_PER_SEC;
        
        cout << "Average Unordered Set Insertion Time: " << avgUnorderedSetInsertionTime << endl;
        
        
        //UNORDERED SET FIND TIME 
        unordered_set<string> us;
        unorderedSetInsertion(50000, words, us);
        
        float avgUnorderedSetFindTime = 0.0;
        // check insertion times
        for(int i = 0; i < 10; ++i){
            random_shuffle(words.begin(), words.end());
            
            clock_t t;
            t = clock();
            findUnorderedSet(n, words, us);
            t = clock() - t;
            
            avgUnorderedSetFindTime += t;
        }
        
        avgUnorderedSetFindTime = avgUnorderedSetFindTime / 10;
        avgUnorderedSetFindTime = ((float)avgUnorderedSetFindTime) / CLOCKS_PER_SEC;
        
        cout << "Average Unordered Set Find Time: " << avgUnorderedSetFindTime << endl;
        cout << endl;
        
        //write to data.txt
        fout << n << ' ' << avgSetInsertionTime << ' ' << avgUnorderedSetInsertionTime << ' ' << avgSetFindTime << ' ' << avgUnorderedSetFindTime << endl;
 
    }
}