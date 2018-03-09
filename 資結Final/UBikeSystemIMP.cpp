#include "UBikeSystemIMP.h"

void UBikeSystemIMP::InitDistTable(std::string MapFile)
{
	priceTable.calcAllPairsShortestPath(MapFile);
}
void UBikeSystemIMP::NewBike(std::string classType, std::string license, int mile, std::string station)
{
	UBike *u = new UBike();
	u->classType = classType;
	u->license = license;
	u->mileage = mile;
	u->isRented = false;
	u->station = station;
	
	ubHashTable.addUBikePtr(u);
	ubStations.at(station).at(classType).addUBikePtr(u);	//heapindex entered in
}
void UBikeSystemIMP::JunkIt(std::string license)
{
	UBike *u = ubHashTable.findUBikePtr(license,false);	//step1: get the bike
	//maybe the license can's be found ? -> return nullptr
	if(u!=nullptr&&!u->isRented){
		UBike *ptr = ubHashTable.findUBikePtr(license,true);	//if so, then remove
		ubStations.at(ptr->station).at(ptr->classType).removeUBikePtr(ptr->heapIndex);
	}
}
void UBikeSystemIMP::Rent(std::string classType, std::string station)
{
	UBikeHeapIMP &heap = ubStations.at(station).at(classType);
	if(!heap.isEmpty()){
		UBike *u = heap.removeUBikePtr(1);
		ubStations.at(station).at(HeapNames[0]).addUBikePtr(u);	//in function change heapindex
		u->isRented = true;
	}
}
void UBikeSystemIMP::Return(std::string station, std::string license, int returnMile)
{
	UBike *u = ubHashTable.findUBikePtr(license,false);
	if(u!=nullptr&&u->isRented){
		net += priceTable.calcPrice(returnMile - u->mileage,u->classType,u->station,station);
		u->mileage = returnMile;
		u->isRented = false;
		UBike *ptr = ubStations.at(u->station).at(HeapNames[0]).removeUBikePtr(u->heapIndex);
		//ptr->station = station;
		ubStations.at(ptr->station).at(ptr->classType).addUBikePtr(ptr);
	}
}
void UBikeSystemIMP::Trans(std::string station, std::string license)
{
	UBike *u = ubHashTable.findUBikePtr(license,false);
	if(u!=nullptr&&!u->isRented){
		UBike *ptr = ubStations.at(u->station).at(u->classType).removeUBikePtr(u->heapIndex);
		ptr->station = station;		//change the station
		ubStations.at(ptr->station).at(ptr->classType).addUBikePtr(ptr);
	}
}
void UBikeSystemIMP::ShutDown()
{
    ubStations.clear();
    for(int i=0;i<256;i++){
    	ubHashTable[i].clear();
	}
}
