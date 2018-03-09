#include "UBikeHeapIMP.h"

void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
	if((*this).isEmpty()){
		//UBikeHeapADT();
		(*this)[1] = ubptr;
		ubptr->heapIndex = 1;
		number = 1;
	}else{		//min heap decided by mileage
		int cur = ++number;
		while(cur!=1 && (*this)[cur/2]->mileage > ubptr->mileage){
			(*this)[cur] = (*this)[cur/2];
			(*this)[cur]->heapIndex = cur;
			cur /= 2;
		}
		ubptr->heapIndex = cur;
		(*this)[cur] = ubptr;	
	}
}
UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
	if(heapIndex<=number){
		UBike *ptr = (*this)[heapIndex];
		if(heapIndex==number){		//remove the last -> needn't change
			number--;
			(*this)[heapIndex] = nullptr;
			return ptr;
		}
		(*this)[heapIndex] = nullptr;		//delete node
		UBike *tmp = (*this)[number--];		//last node
		int cur = heapIndex;
		if(cur!=1 && (*this)[cur/2]->mileage > tmp->mileage){	//bubble-up ?
			while(cur!=1 && (*this)[cur/2]->mileage > tmp->mileage){
				(*this)[cur] = (*this)[cur/2];
				(*this)[cur]->heapIndex = cur;
				cur /= 2;
			}
			tmp->heapIndex = cur;
			(*this)[cur] = tmp;
		}else{													//bubble-down ?
			int child = cur*2;
			while(child<=number){
				if(child+1<=number && (*this)[child]->mileage > (*this)[child+1]->mileage ){
					child++;
				}
				if(tmp->mileage <= (*this)[child]->mileage)	break;
				(*this)[cur] = (*this)[child];
				(*this)[cur]->heapIndex = cur;
				cur = child;	child *= 2;
			}
			tmp->heapIndex = cur;
			(*this)[cur] = tmp;
		}
		return ptr;
	}else	return nullptr;
	
}
