#include "Implement.h"

void Implement::InsertBack(int data){
	Node *ptr = new Node();
	ptr->data = data;
	ptr->next = nullptr;
	if(head==nullptr){
		head = ptr;
	}else{
		Node *tmp = head;
		while(tmp->next!=nullptr)	tmp = tmp->next;
		tmp->next = ptr;
	}
}
void Implement::InsertAfter(int data1, int data2){
	if(head==nullptr)	return;
	else{
		Node *tmp = head;
		while(tmp->data!=data1&&tmp->next!=nullptr)	tmp = tmp->next;
		if(tmp->data==data1){
			Node *ptr = new Node();
			ptr->data = data2;
			ptr->next = tmp->next;	//if(tmp->next==nullptr) ptr->next=nullptr;
			tmp->next = ptr;
		}
	}
}
void Implement::Delete(int data){
	Node *now = head, *prev = nullptr;
	if(now==nullptr)	return;		//isEmpty
	while(now->data!=data&&now->next!=nullptr){
		prev = now;
		now = now->next;
	}
	if(now->data==data){
		if(now==head){
			head = head->next;
		}else{
			prev->next = now->next;
			//free(now);
		}
	}
}
void Implement::Reverse(){
	Node *now = head;
	Node *prev = nullptr;
	while(now!=nullptr){
		Node *tmp = prev;
		prev = now;
		now = now->next;
		prev->next = tmp;
	}
	head = prev;
}
