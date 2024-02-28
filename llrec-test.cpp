#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"

using namespace std;


/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        std::cout << "Please provide an input file" << std::endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    std::cout << "Original list: ";
    print(head);

    // Test out your linked list code

    // Testing llpivot:
    // int pivot = 10; 
    // std::cout << "Pivot: " << pivot << endl; 

    // Test 1 (Empty smaller & larger lists):
    #ifdef TEST1
    Node* smaller = nullptr; 
    Node* larger = nullptr; 
    cout << "TEST 1 - Testing with smaller & larger being empty" << endl; 
    llpivot(head, smaller, larger, pivot);

    cout << "Head list (Should be empty)" << endl; 
    print(head); 
    cout << endl; 

    cout << "Smaller list (Should be less than " << pivot << ")" << endl;
    print(smaller);
    cout << endl;

    cout << "Larger list (Should be larger than " << pivot << ")" << endl;
    print(larger);
    cout << endl; 
    return 0;
    #endif

    // Test 2 (Nonempty smaller & empty larger lists):
    #ifdef TEST2
    Node* smaller = new Node(0, nullptr); 
    Node* larger = nullptr; 
    cout << "TEST 2 - (Nonempty smaller & empty larger lists)" << endl; 
    llpivot(head, smaller, larger, pivot);

    cout << "Head list (Should be empty)" << endl; 
    print(head); 
    cout << endl; 

    cout << "Smaller list (Should be less than " << pivot << ")" << endl;
    print(smaller);
    cout << endl;

    cout << "Larger list (Should be larger than " << pivot << ")" << endl;
    print(larger);
    cout << endl; 

    delete smaller;
    #endif

    // Test 3 (Nonempty smaller w/ multiple items & empty larger lists)
    #ifdef TEST3
    Node* newNode5 = new Node(5, nullptr); 
    Node* newNode4 = new Node(4, newNode5); 
    Node* newNode3 = new Node(3, newNode4);
    Node* newNode2 = new Node(2, newNode3);
    Node* smaller = new Node(1, newNode2); // newNode1

    Node* larger = nullptr; 
    cout << "TEST 3 - (Nonempty smaller w/ multiple items & empty larger lists)" << endl; 
    llpivot(head, smaller, larger, pivot);

    cout << "Head list (Should be empty)" << endl; 
    print(head); 
    cout << endl; 

    cout << "Smaller list (Should be less than " << pivot << ")" << endl;
    print(smaller);
    cout << endl;

    cout << "Larger list (Should be larger than " << pivot << ")" << endl;
    print(larger);
    cout << endl; 

    delete newNode5;
    delete newNode4;
    delete newNode3;
    delete newNode2;
    delete smaller; 
    #endif

    // Test 4 (Nonempty smaller w/ multiple items & nonempty larger w/ single item)
    #ifdef TEST4
    Node* newNode5 = new Node(5, nullptr); 
    Node* newNode4 = new Node(4, newNode5); 
    Node* newNode3 = new Node(3, newNode4);
    Node* newNode2 = new Node(2, newNode3);
    Node* smaller = new Node(1, newNode2); // newNode1

    Node* larger = new Node(50, nullptr); 
    cout << "TEST 4 - (Nonempty smaller w/ multiple items & nonempty larger w/ single item)" << endl; 
    llpivot(head, smaller, larger, pivot);

    cout << "Head list (Should be empty)" << endl; 
    print(head); 
    cout << endl; 

    cout << "Smaller list (Should be less than " << pivot << ")" << endl;
    print(smaller);
    cout << endl;

    cout << "Larger list (Should be larger than " << pivot << ")" << endl;
    print(larger);
    cout << endl; 

    delete newNode5;
    delete newNode4;
    delete newNode3;
    delete newNode2;
    delete smaller; 
    delete larger; 
    #endif

    // Test 5 (Nonempty smaller w/ multiple items & nonempty larger w/ multiple items)
    #ifdef TEST5
    Node* newNode5 = new Node(5, nullptr); 
    Node* newNode4 = new Node(4, newNode5); 
    Node* newNode3 = new Node(3, newNode4);
    Node* newNode2 = new Node(2, newNode3);
    Node* smaller = new Node(1, newNode2); // newNode1

    Node* newNode50 = new Node(50, nullptr);
    Node* newNode49 = new Node(49, newNode50); 
    Node* newNode48 = new Node(48, newNode49); 
    Node* newNode47 = new Node(47, newNode48); 
    Node* larger = new Node(46, newNode47); // newNode46


    cout << "TEST 5 - (Nonempty smaller w/ multiple items & nonempty larger w/ multiple items)" << endl; 
    llpivot(head, smaller, larger, pivot);

    cout << "Head list (Should be empty)" << endl; 
    print(head); 
    cout << endl; 

    cout << "Smaller list (Should be less than " << pivot << ")" << endl;
    print(smaller);
    cout << endl;

    cout << "Larger list (Should be larger than " << pivot << ")" << endl;
    print(larger);
    cout << endl; 

    delete newNode5;
    delete newNode4;
    delete newNode3;
    delete newNode2;
    delete smaller; 

    delete newNode50;
    delete newNode49;
    delete newNode48;
    delete newNode47;
    delete larger; 
    #endif

    // Testing llfilter:
    struct pred{
        pred(int userInput) : storedVal(userInput)
        {
        }

        bool operator()(int x){
            if (this->storedVal == x){
                return true;
            }

            return false;
        }

        int storedVal; 
    };

    // Test 6
    #ifdef TEST6
    pred firstPred = pred(8); 
    head = llfilter<pred>(head, firstPred);
    cout << "TEST 6 - Filtering #8 (Front and back should be removed)\n";
    cout << "List after filtering out " << firstPred.storedVal << ": "; 
    print(head);
    #endif

    // Test 7
    #ifdef TEST7
    pred firstPred = pred(9); 
    head = llfilter<pred>(head, firstPred);
    cout << "TEST 7 - Filtering #9 (Second should be removed)\n";
    cout << "List after filtering out " << firstPred.storedVal << ": "; 
    print(head);
    #endif

    // Test 8
    #ifdef TEST8
    pred firstPred = pred(9); 
    head = llfilter<pred>(head, firstPred);
    cout << "TEST 7 - Filtering #8 and then #9\n";
    cout << "List after filtering out " << firstPred.storedVal << ": "; 
    print(head);

    pred secondPred = pred(8); 
    head = llfilter<pred>(head, secondPred); 
    cout << "List after filtering out " << secondPred.storedVal << ": "; 
    print(head);
    #endif

    #ifdef TEST9

    #endif


    return 0;
}
