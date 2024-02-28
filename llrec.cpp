#include "llrec.h"



//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    smaller = nullptr;
    larger = nullptr; 

    if (head == nullptr){
        return; 
    }

    newLlpivotHelper(head, smaller, larger, pivot);
}

// Literally just the same without assigning smaller and larger to nullptr
void newLlpivotHelper(Node *& head, Node *&smaller, Node *&larger, int pivot){
    if (head == nullptr){
        return; 
    }
    
    // If val is less than or equal to pivot
    if (head->val <= pivot){
        // If smaller is empty
        // Assign head pointer of smaller to head node
        smaller = head;

        // Shift head node to next val in the original list 
        head = head->next;

        // Set the new smaller node's next to nullptr to break off link
        // from original list
        smaller->next = nullptr; 

        // Call function again, with smaller->next to not lose smaller head pointer 
        newLlpivotHelper(head, smaller->next, larger, pivot); 
    }

    // If val is greater than pivot
    else if (head->val > pivot){
        // Set larger head pointer to head node
        larger = head;

        // Shift head node to next val in the original list 
        head = head->next;

        // Set the new larger node's next to nullptr to break off link
        // from original list
        larger->next = nullptr; 

        // Call function again with larger->next to not lose larger head pointer
        newLlpivotHelper(head, smaller, larger->next, pivot); 
    }
}

// Ignore:
Node*& llpivotHelper(Node*& list){
    // If list is null (empty), return list
    if (list == nullptr){
        return list;
    }

    // If the next item is null, that means current node is last item
    // therefore return last item
    if (list->next == nullptr){
        return list;
    }

    // Recursively go to the next item
    return llpivotHelper(list->next);
}

// Junk
/*

        // // cout << "head->val:\n"; 
        // // cout << head->val << endl; 

        // // Get last item of smaller list
        // Node* lastItemOfSmaller = llpivotHelper(smaller);
        // if (lastItemOfSmaller->next == nullptr){
        //     cout << "HELLO?" << endl; 
        // }

        // else{
        //     cout << lastItemOfSmaller->next->val << endl;
        // }

        // // Assign next item of smaller list is head
        // // If list is empty (i.e. lastItemOfSmaller is a head pointer)
        // if (lastItemOfSmaller == nullptr){
        //     lastItemOfSmaller = head;
        // }
        
        // // If list is not empty (i.e. lastItemOfSmaller is not a head pointer)
        // else if (lastItemOfSmaller != nullptr){
        //     lastItemOfSmaller->next = head;
        // }

        // cout << "lastItemVal: " << lastItemOfSmaller->val << endl; 

        // // Now the new last item is head
        // lastItemOfSmaller = lastItemOfSmaller->next;

        // llpivot(head->next, lastItemOfSmaller, larger, pivot);
        

                if (smaller == nullptr){
            smaller = head;
            llpivot(head->next, smaller->next, larger, pivot);
        }
        
        Node* lastItemOfSmaller = llpivotHelper(smaller); 
        
        if (lastItemOfSmaller == nullptr){
            lastItemOfSmaller = head;
            // cout << lastItemOfSmaller->val; 
            llpivot(head->next, smaller, larger, pivot); 
        }

        else if (lastItemOfSmaller != nullptr){
            lastItemOfSmaller->next = head;
            llpivot(head->next, smaller, larger, pivot); 
        }
    }
*/

// Original
/*

    if (head == nullptr){
        return;
    }

    // If value is less than or equal to than pivot
    if (head->val <= pivot){

        // If smaller is empty
        if (smaller == nullptr){
            // Assign head pointer of smaller to head node
            smaller = head;

            // Shift head node to next val in the original list 
            head = head->next;

            // Set the new smaller node's next to nullptr to break off link
            // from original list
            smaller->next = nullptr; 

            // Call llpivot again 
            llpivot(head, smaller, larger, pivot); 
        }

        // If smaller is not empty
        else if (smaller != nullptr){
            // Find last node
            Node* lastNode = llpivotHelper(smaller); 
            smaller = lastNode; 

            // Add head node to back of list 
            lastNode->next = head;

            // Shift head node to next val in the original list 
            head = head->next; 

            // "lastNode" is no longer the last node of the list, since we added one
            // So we need to set the next value (that we just added) and set that next
            // to nullptr to break off link from original list
            lastNode->next->next = nullptr;

            // Call llpivot again 
            llpivot(head, smaller, larger, pivot); 
        }
    }

    // If value is greater than pivot
    else if (head->val > pivot){
        
        // If larger is empty
        if (larger == nullptr){
            // Set larger head pointer to head node
            larger = head;

            // Shift head node to next val in the original list 
            head = head->next;

            // Set the new larger node's next to nullptr to break off link
            // from original list
            larger->next = nullptr; 

            // Call llpivot again 
            llpivot(head, smaller, larger, pivot); 
        }

        else if (larger != nullptr){
            // Find last node
            Node* lastNode = llpivotHelper(larger);

            // Add head node to back of list  
            lastNode->next = head;

            // Shift head node to next val in the original list 
            head = head->next; 
            
            
            // "lastNode" is no longer the last node of the list, since we added one
            // So we need to set the next value (that we just added) and set that next
            // to nullptr to break off link from original list
            lastNode->next->next = nullptr; 

            // Call llpivot again 
            llpivot(head, smaller, larger, pivot); 
        }
    }

*/