#ifndef PriceTableIMP_h
#define PriceTableIMP_h

#include "readonly/PriceTableADT.h"
#include <fstream>

class PriceTableIMP : public PriceTableADT
{
public:
	void calcAllPairsShortestPath(std::string mapFile);
    int calcPrice(int milageDiff, std::string bClass, std::string from, 
					std::string toStation);
};

#endif
