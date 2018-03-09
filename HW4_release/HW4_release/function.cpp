#include "function.h"
void Implement::addEdge(const int label_1, const int label_2, const int weight)
{
	int idx1 = -1, idx2 = -1;
	if(label_1==label_2)	return;		//ensure no self cycle edge
	for(int i=0;i<VertexArr.size();i++){	//find the index of label 1 & 2
		if(VertexArr[i].label==label_1){
			idx1 = i;
		}else if(VertexArr[i].label==label_2){
			idx2 = i;
		}
		if(idx1!=-1&&idx2!=-1)	break;
	}
	//if label 1 or 2 not yet existed
	if(idx1==-1){
		Vertex a(label_1);
		VertexArr.push_back(a);
		idx1 = VertexArr.size() - 1;
	}
	if(idx2==-1){
		Vertex b(label_2);
		VertexArr.push_back(b);
		idx2 = VertexArr.size() - 1;
	}
	for(int i=0;i<VertexArr[idx1].neighbors.size();i++){	//if edge already existed
		if(VertexArr[idx1].neighbors[i].label==label_2){
			return;
		}
	}
	Neighbor bb(label_2,weight);
	VertexArr[idx1].neighbors.push_back(bb);
	Neighbor aa(label_1,weight);
	VertexArr[idx2].neighbors.push_back(aa);
}
void Implement::deleteEdge(const int label_1, const int label_2)
{
	int record = 0;
	for(int i=0;i<VertexArr.size()&&record<2;i++){
		if(VertexArr[i].label==label_1||VertexArr[i].label==label_2){
			for(int j=0;j<VertexArr[i].neighbors.size();j++){
				if(VertexArr[i].neighbors[j].label==label_1||VertexArr[i].neighbors[j].label==label_2){
					VertexArr[i].neighbors.erase(VertexArr[i].neighbors.begin()+j);
					record++;
					break;
				}
			}
			if(record==0)	return;
		}
	}
}
void Implement::deleteVertex(const int label)
{
	for(int i=0;i<VertexArr.size();i++){
		if(VertexArr[i].label==label){
			for(int j=0;j<VertexArr.size();j++){
				if(j!=i){
					for(int k=0;k<VertexArr[j].neighbors.size();k++){
						if(VertexArr[j].neighbors[k].label==label){
							VertexArr[j].neighbors.erase(VertexArr[j].neighbors.begin()+k);
							break;
						}
					}
				}
			}
			VertexArr[i].neighbors.clear();
			VertexArr.erase(VertexArr.begin()+i);
			return;
		}
	}
}
int Implement::degree(const int label)
{
	for(int i=0;i<VertexArr.size();i++){
		if(VertexArr[i].label==label){
			return VertexArr[i].neighbors.size();
		}
	}
	return 0;
}
bool Implement::isExistPath(const int label_1, const int label_2)
{
	std::vector<Vertex> mem;
	std::vector<Neighbor> tmp;
	for(int i=0;i<VertexArr.size();i++){
		if(VertexArr[i].label==label_1){
			tmp = VertexArr[i].neighbors;
		}
	}
	bool record = false;
	while(!tmp.empty()){
		Neighbor check = tmp.back();
		tmp.pop_back();
		for(int i=0;i<mem.size();i++){
			if(mem[i].label==check.label){
				record = true;
				break;
			}
		}
		if(record==true){
			record = false;
			continue;
		}
		if(check.label==label_2)	return true;
		for(int i=0;i<VertexArr.size();i++){
			if(VertexArr[i].label==check.label){
				for(int j=0;j<VertexArr[i].neighbors.size();j++){
					tmp.push_back(VertexArr[i].neighbors[j]);
				}
				mem.push_back(VertexArr[i]);
				break;
			}
		}
	}
	return false;
}
void Implement::deleteGraph()
{
	for(int i=0;i<VertexArr.size();i++){
		VertexArr[i].neighbors.clear();
	}
	VertexArr.clear();
}
int Implement::number_of_component()
{
	if(VertexArr.empty())	return 0;
	else{
		int visited[100] = {0};		//record by "label"
		int num = 0;
		for(int i=0;i<VertexArr.size();i++){
			if(visited[VertexArr[i].label])	continue;
			std::vector<Vertex> rem;
			rem.push_back(VertexArr[i]);
			while(!rem.empty()){		//DFS
				Vertex a = rem.back();
				rem.pop_back();
				int idx = -1;
				for(int j=0;j<VertexArr.size();j++){
					if(VertexArr[j].label==a.label){
						idx = j;
						break;
					}
				}
				if(!visited[a.label]){
					visited[a.label] = 1;
					for(int j=0;j<VertexArr[idx].neighbors.size();j++){
						if(!visited[VertexArr[idx].neighbors[j].label]){
							int tmp = -1;
							for(int k=0;k<VertexArr.size();k++){
								if(VertexArr[k].label==VertexArr[idx].neighbors[j].label){
									tmp = k;
									break;
								}
							}
							if(tmp!=-1)	rem.push_back(VertexArr[tmp]);
						}
					}
				}
			}
			num++;
		}
		return num;
	}
}
