#include "UBikeHashTableIMP.h"

void UBikeHashTableIMP::addUBikePtr(UBike* ubptr)
{
	int X[5] = {0};
	for(int i=0;i<5;i++){
		if(isalpha(ubptr->license[i])){
			X[i] = (ubptr->license[i] - 'A') + 10;
		}else{
			X[i] = (ubptr->license[i] - '0');
		}
	}
	int sum = X[4] + 29*(X[3]+29*(X[2]+29*(X[1]+29*X[0])));
	int addr = (sum % (int)pow(2,13)) / (int)pow(2,5) ;
	(*this)[addr].push_front(ubptr);
}
UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove)
{
	int X[5] = {0};
	for(int i=0;i<5;i++){
		if(isalpha(license[i])){
			X[i] = (license[i] - 'A') + 10;
		}else{
			X[i] = (license[i] - '0');
		}
	}
	int sum = X[4] + 29*(X[3]+29*(X[2]+29*(X[1]+29*X[0])));
	int addr = (sum % (int)pow(2,13)) / (int)pow(2,5) ;
	if((*this)[addr].empty()){
		return nullptr;
	}else{
		int find = 0;
		UBike *ptr = nullptr;
		for(auto it=(*this)[addr].begin();it!=(*this)[addr].end();it++){
			if((*it)->license==license){
				ptr = (*it);
				find = 1;
				break;
			}
		}
		if(find==0)	return nullptr;
		if(toRemove==true){			//will it cause error ?
			UBike *tmp = ptr;
			(*this)[addr].remove(ptr);
			return tmp;
		}else{
			return ptr;
		}
	}
}
