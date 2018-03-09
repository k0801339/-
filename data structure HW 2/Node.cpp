//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include "Node.h"

Node::Node()
{
	this->next = NULL;
}

Node::Node(const int e, Node* next = NULL) 
{
	this->data = e;
	this->next = next;
}

Node::~Node()
{
	this->next = NULL;
}
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
