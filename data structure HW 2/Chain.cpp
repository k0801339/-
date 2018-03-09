//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include "Chain.h"


void Chain::InsertBack(int data)
{
	throw "[Undefined Chain::InsertBack]";
}

void Chain::InsertAfter(int data1, int data2)
{
	throw "[Undefined Chain::InsertAfter]";
}

void Chain::Delete(int data)
{
	throw "[Undefined Chain::Delete]";
}

void Chain::Reverse()
{
    throw "[Undefined Chain::Reverse]";
}

std::string Chain::toString() 
{
	Node* tmp = this->head;
	string result = "";
	if(tmp == NULL){
		result.append("Empty");
	} 
	while(tmp != NULL) {
		std::string num = std::to_string(tmp->data);
		result.append(num);
		if(tmp->next != NULL) 
			result.append("->");
		tmp = tmp->next;
	}
	return result;
}
//========================DO-NOT-MODIFY-THE-FILE======================== 
