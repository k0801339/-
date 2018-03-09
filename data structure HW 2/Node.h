//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef Node_h
#define Node_h
#include <string>

//The data structure that present a node.
class Node
{
friend class Chain;
public:
    //the pointer to next node in the chain
	Node *next;

    //stores the data
    int data;
	
	//constructor and destructor
	Node();
	Node(const int e, Node* next);
	~Node();
};

#endif
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================