#include "stack.h"
#include "iostream"

using namespace std; 

int main(){
    Stack<int> myInt;
    myInt.push(0);
    myInt.push(1); 
    myInt.push(2); 
    myInt.push(3); 
    myInt.push(4); 
    myInt.push(5);

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n";
    myInt.pop(); 

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n"; 
    myInt.pop(); 

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n"; 
    myInt.pop(); 

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n"; 
    myInt.pop(); 

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n"; 
    myInt.pop(); 

    cout << "Front item: " << myInt.top() << endl;

    cout << "Popping top item\n"; 
    myInt.pop(); 

    return 0;  

}