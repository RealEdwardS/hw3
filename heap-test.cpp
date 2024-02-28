#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;


int main(){
    cout << "Creating heap\n"; 
    
    Heap<int> h1; 

    #ifdef TEST10
    vector<int> myList = {25, 16, 43, 36, 39, 28, 10, 14, 35, 19, 9, 18, 7};

    for (unsigned int i = 0; i < myList.size(); ++i){
        cout << "Pushing " << myList.at(i) << endl; 
        h1.push(myList.at(i)); 
    }

    cout << "Printing list" << endl; 
    h1.printList(); 

    cout << "\nPushing back 8" << endl;
    h1.push(8);
    h1.printList(); 

    cout << "\nPushing back 0" << endl;
    h1.push(0);
    h1.printList(); 
    #endif

    #ifdef TEST11
    vector<int> myList = {7, 18, 9, 19, 35, 14, 10, 28, 39, 36, 43, 16, 25}; 
    
    for (unsigned int i = 0; i < myList.size(); ++i){
        cout << "Pushing " << myList.at(i) << endl; 
        h1.push(myList.at(i)); 
    }

    cout << "Printing list" << endl; 
    h1.printList(); 

    cout << "\nPopping 7" << endl;
    h1.pop(); 
    h1.printList();
    #endif

    return 0; 
}