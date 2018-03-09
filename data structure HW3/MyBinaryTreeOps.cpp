#include "MyBinaryTreeOps.h"
Node* MyBinaryTreeOps::constructTree(Node *root, std::string treeStr) const
{
	int idx = 0;
	int token = 0, neg = 1, record=0;
	Node *left = nullptr, *right = nullptr;
	while(idx<treeStr.length()){
		if(treeStr[idx]=='('){
			if(record==0){
				idx++;
			}else{
				token *= neg;
				root = new Node(token);
				root->weight = token;
				std::stack<char> trash;
				std::string a, b;
				a.push_back(treeStr[idx]);
				trash.push(treeStr[idx++]);
				while(!trash.empty()){
					if(treeStr[idx]=='(')	trash.push(treeStr[idx]);
					else if(treeStr[idx]==')')	trash.pop();
					a.push_back(treeStr[idx]);
					++idx;
				}
				root->left = constructTree(left,a);
				a.clear();

				b.push_back(treeStr[idx]);
				trash.push(treeStr[idx++]);
				while(!trash.empty()){
					if(treeStr[idx]=='(')	trash.push(treeStr[idx]);
					else if(treeStr[idx]==')')	trash.pop();
					b.push_back(treeStr[idx]);
					++idx;
				}
				root->right = constructTree(right,b);
				b.clear();
			}
		}else if(treeStr[idx]==')'){
			idx++;
		}else{
			if(treeStr[idx]=='-'){
				neg = -1;
			}else if(treeStr[idx]>='0'&&treeStr[idx]<='9'){
				token = token*10 + (treeStr[idx] - '0');
			}
			record = 1;
			idx++;
		}
	}
	return root;
}
Node* MyBinaryTreeOps::deleteTree(Node *root) const
{
	if(root!=nullptr){
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		//root = nullptr;
	}
	return nullptr;
}
int MyBinaryTreeOps::treeHeight(const Node *root) const
{
	if(root!=nullptr){
		int _left = treeHeight(root->left);
		int _right = treeHeight(root->right);
		return std::max(_left,_right) + 1;
	}
	return 0;
}
int MyBinaryTreeOps::treeWeight(const Node *root) const
{
	if(root!=nullptr){
		int _left = treeWeight(root->left);
		int _right = treeWeight(root->right);
		return (_left + _right + root->weight);
	}
	return 0;
}
int MyBinaryTreeOps::leafNum(const Node *root) const
{
	if(root!=nullptr){
		int _left = leafNum(root->left);
		int _right = leafNum(root->right);
		if(root->left==nullptr&&root->right==nullptr)
			return 1;
		else
			return (_left+_right);
	}
	return 0;
}
int MyBinaryTreeOps::maxPathWeight(const Node *root) const
{
	if(root!=nullptr){
		int _left, _right, isleft=0, isright=0;
		if(root->left!=nullptr){
			_left = maxPathWeight(root->left);
			isleft = 1;
		}
		if(root->right!=nullptr){
			_right = maxPathWeight(root->right);
			isright = 1;
		}
		//consider: no node(weight=0) may "bigger" than node<0
		if(!isleft&&!isright)	return root->weight;
		else if(isleft&&isright)	return (std::max(_left,_right) + root->weight);
		else if(isleft&&!isright)	return (_left + root->weight);
		else	return (_right + root->weight);
	}
	return 0;
}

