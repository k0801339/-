//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef Chain_H
#define Chain_H
#include "Node.h"
using namespace std;

//It contains the fucntions that you have to override in implement.h/.cpp.
class Chain
{
public:
    //----------------------------------------------------------------------
    // Insert a data at the end of the linked list.
	// e.g. original list (head) : "A -> B" => InsertBack(head, C) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual void InsertBack(int data);

    //----------------------------------------------------------------------
    // Insert data2 after data1 in the linked list. 
	// If the InsertAfter error happened , do nothing.
	// e.g. original list (head) : "A -> A" => InsertAfter(head, A, B) => "A -> B -> A"
	// e.g. original list (head) : "A -> A" => InsertAfter(head, C, B) => "A -> A"
    //----------------------------------------------------------------------
    virtual void InsertAfter(int data1, int data2);
   
    //----------------------------------------------------------------------
    // Remove the data from the linked list. 
	// If the Delete error happened , do nothing.
	// e.g. original list (head) : "A -> B -> C" => Delete(head,B) => "A -> C"
	// e.g. original list (head) : "A -> B -> C" => Delete(head,Y) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual void Delete(int data);
   
    //----------------------------------------------------------------------
    // Reverse the linked list.
	// e.g. original list (head) : "A -> B -> C" =>Reverse(head) => "C -> B -> A"
    //----------------------------------------------------------------------
    virtual void Reverse();

    string toString();
	
	Node* head = NULL;
};
#endif
//========================DO-NOT-MODIFY-THE-FILE======================== 