#ifndef Implement_H
#define Implement_H

#include "Chain.h"

class Implement : public Chain
{
public:
    void InsertBack(int data);
	void InsertAfter(int data1, int data2);
	void Delete(int data);
	void Reverse();
    
};

#endif
