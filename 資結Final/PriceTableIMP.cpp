#include "PriceTableIMP.h"

void PriceTableIMP::calcAllPairsShortestPath(std::string mapFile)
{
	std::string sta1, sta2;
	int len;
	std::ifstream ifs(mapFile);
	while(ifs>>sta1>>sta2>>len){
		//int num = std::stoi(len);
		distTable[sta1][sta2] = len;
		distTable[sta2][sta1] = len;
	}
	for(int k=0;k<StationNum;k++){
		for(int i=0;i<StationNum;i++){
			for(int j=0;j<StationNum;j++){
				const std::string &sti = StationNames[i];
        		const std::string &stj = StationNames[j];
        		const std::string &stk = StationNames[k];
				//has route: i -> k -> j
				if(sti!=stj && distTable[sti][stk]!=0 && distTable[stk][stj]!=0){	
					if(distTable[sti][stk]+distTable[stk][stj] < distTable[sti][stj] || distTable[sti][stj]==0){
						distTable[sti][stj] = distTable[sti][stk]+distTable[stk][stj];
					}
				}
			}
		}
	}
}
int PriceTableIMP::calcPrice(int milageDiff, std::string bClass, std::string from
						, std::string toStation)
{
	if(milageDiff<=distTable[from][toStation]){
		return milageDiff * dscntRates.at(bClass);
	}else{
		return milageDiff * oriRates.at(bClass);
	}
}
