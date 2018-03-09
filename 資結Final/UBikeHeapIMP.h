#ifndef UBikeHeapIMP_h
#define UBikeHeapIMP_h

#include "UBikeHeapADT.h"
#include <iostream>

class UBikeHeapIMP : public UBikeHeapADT
{
public:
    void addUBikePtr(UBike* ubptr);
    UBike* removeUBikePtr(int heapIndex);
};

#endif
