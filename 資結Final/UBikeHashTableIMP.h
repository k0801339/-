#ifndef UBikeHashTableIMP_h
#define UBikeHashTableIMP_h

#include "UBikeHashTableADT.h"
#include<cmath>
#include<iostream>

class UBikeHashTableIMP : public UBikeHashTableADT
{
public:
    void addUBikePtr(UBike* ubptr);
    UBike* findUBikePtr(std::string license, bool toRemove);
};

#endif
