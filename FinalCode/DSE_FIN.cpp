#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#define SIZE 7;; 

const int TABLE_SIZE = 7;


using namespace std;
vector <string> split(string str, char Delimiter) {
	istringstream iss(str);
	string buffer;
	vector <string> result; //구분자 기준으로 절삭된 문자열이 담김

	while (getline(iss, buffer, Delimiter))
	{
		result.push_back(buffer);
	}
	return result;

}


class Trash {
public:
	int Number;
	string Name;
	int Widths;
	int Hights;
	double Latitude;
	double Longitude;
	int Rubbish;
	int Plastics;
	int Cans;
	int Glass;
	int Papers;
	string TrashType;
	double TrashWeight;
	double TrashPrice;
	string TrashLocation;
	Trash() { TrashWeight = 0.0, TrashPrice = 0.0, Latitude = 0.0, Longitude = 0.0; }
	Trash(string row)
	{
		vector<string> s = split(row, ',');
		Number = stoi(s[0]);
		Name = s[1];
		Widths = stoi(s[2]);
		Hights = stoi(s[3]);
		Latitude = stod(s[4]);
		Longitude = stod(s[5]);
		Rubbish = stoi(s[6]);
		Plastics = stoi(s[7]);
		Cans = stoi(s[8]);
		Glass = stoi(s[9]);
		Papers = stoi(s[10]);
		TrashType = s[11];
		TrashWeight = stoi(s[12]);
		TrashPrice = stoi(s[13]);
		TrashLocation = s[14];
	}
	Trash(int N, string TN, int W, int H, double La, double Lo, int Rb, int Plt, int C, int G, int P, string TT, double TW, double TP, string TL)
		:Number(N), Name(TN), Widths(W), Hights(H), Latitude(La), Longitude(Lo), Rubbish(Rb), Plastics(Plt), Cans(C), Glass(G), Papers(P), TrashType(TT), TrashWeight(TW), TrashPrice(TP), TrashLocation(TL) { };
};

class Trash2 {
public:
	string TrashType2;
	double TrashPrice2;
	int TrashQuantity2;
	Trash2() { TrashPrice2 = 0.0; TrashQuantity2 = 0; }
	Trash2(string row)
	{
		vector<string> s2 = split(row, ',');
		TrashType2 = s2[11];
		TrashPrice2 = stoi(s2[13]);
		TrashQuantity2 = 1;
	}
	Trash2(string TT, double TP)
		:TrashType2(TT), TrashPrice2(TP) {TrashQuantity2 = 1;};
};

class AVLNode {
public:
	Trash key;
	int rank = 0;
	AVLNode* left;
	AVLNode* right;
	AVLNode() { left = right = NULL; }
	AVLNode(string name) { key.Name = name; }
	AVLNode(Trash t)
		:key(t) {
		left = NULL; right = NULL;
	}

};

class AVLNode2 {
public:
	Trash2 key2;
	int rank2 = 0;
	AVLNode2* left;
	AVLNode2* right;
	AVLNode2() { left = right = NULL; }
	AVLNode2(string type) { key2.TrashType2 = type; }
	AVLNode2(Trash2 t2)
		:key2(t2) {
		left = NULL; right = NULL;
	}

};


//오른쪽 회전 
AVLNode* rotate_right(AVLNode* parent)
{
	AVLNode* child = parent->left; //현재 서브트리의 루트 노드의 왼쪽 자식을 child 노드로 지정
	parent->left = child->right; //오른쪽 회전
	child->right = parent; //1.child노드가 서브트리의 루트노드가 됨, 2.parent노드가 child노드의 오른쪽 자식노드가 됨 

	return child; //새로운 루트 반환
}
AVLNode2* rotate_right2(AVLNode2* parent)
{
	AVLNode2* child = parent->left; //현재 서브트리의 루트 노드의 왼쪽 자식을 child 노드로 지정
	parent->left = child->right; //오른쪽 회전
	child->right = parent; //1.child노드가 서브트리의 루트노드가 됨, 2.parent노드가 child노드의 오른쪽 자식노드가 됨 

	return child; //새로운 루트 반환
}


//왼쪽 회전 
AVLNode* rotate_left(AVLNode* parent)
{
	AVLNode* child = parent->right; //현재 서브트리의 루트 노드의 오른쪽 자식을 child 노드로 지정
	parent->right = child->left; //왼쪽 회전
	child->left = parent; //1.child노드가 서브트리의 루트노드가 됨, 2.parent노드가 child노드의 왼쪽 자식노드가 됨

	return child;
}
AVLNode2* rotate_left2(AVLNode2* parent)
{
	AVLNode2* child = parent->right; //현재 서브트리의 루트 노드의 오른쪽 자식을 child 노드로 지정
	parent->right = child->left; //왼쪽 회전
	child->left = parent; //1.child노드가 서브트리의 루트노드가 됨, 2.parent노드가 child노드의 왼쪽 자식노드가 됨

	return child;
}


//높이 
int get_height(AVLNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right)); //왼쪽 서브트리 오른쪽 서브트리 중 더 높은 높이가 트리의 높이가 됨
	}
	return height;
}

//노드들의 균형인수 구하기
int get_balance(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return get_height(node->left) - get_height(node->right); //왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
}

int get_height2(AVLNode2* node)
{
	int height2 = 0;
	if (node != NULL)
	{
		height2 = 1 + max(get_height2(node->left), get_height2(node->right)); //왼쪽 서브트리 오른쪽 서브트리 중 더 높은 높이가 트리의 높이가 됨
	}
	return height2;
}
int get_balance2(AVLNode2* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return get_height2(node->left) - get_height2(node->right); //왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
}


//노드 추가 함수
//새로운 루트 반환
AVLNode* insert(AVLNode* node, Trash key)
{
	if (node == NULL) //새로운 노드 추가
	{
		return new AVLNode(key);
	}

	if (key.Name < node->key.Name) //작으면 왼쪽 서브트리로 
	{
		node->left = insert(node->left, key);
	}
	else if (key.Name > node->key.Name) //크면 오른쪽 서브트리로 
	{
		node->right = insert(node->right, key);
	}
	else //동일한 key는 허용하지 않음
	{
		return node;
	}

	//균형 인수 재계산
	int balance = get_balance(node);

	//LL type (왼쪽으로 꺾여있는 타입)
	if (balance > 1 && key.Name < node->left->key.Name)
	{
		return rotate_right(node); //오른쪽으로 1번 회전
	}
	//RR type (오른쪽으로 꺾여있는 타입)
	if (balance < -1 && key.Name > node->right->key.Name)
	{
		return rotate_left(node); //왼쪽으로 1번 회전
	}
	//LR type (왼쪽 1번, 오른쪽 1번 꺾여있는 지그재그 타입)
	if (balance > 1 && key.Name > node->left->key.Name)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node); //왼쪽으로 1번 회전 -> 오른쪽으로 1번 회전
	}
	//RL type (오른쪽 1번, 왼쪽 1번 꺾여있는 지그재그 타입)
	if (balance < -1 && key.Name < node->right->key.Name)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node); //오른쪽으로 1번 회전 -> 왼쪽으로 1번 회전
	}
	return node;
}

AVLNode2* insert2(AVLNode2* node, Trash2 key2)
{
	if (node == NULL) //새로운 노드 추가
	{
		return new AVLNode2(key2);
	}
	if (key2.TrashType2 < node->key2.TrashType2) //작으면 왼쪽 서브트리로 
	{
		node->left = insert2(node->left, key2);
	}
	else if (key2.TrashType2 > node->key2.TrashType2) //크면 오른쪽 서브트리로 
	{
		node->right = insert2(node->right, key2);
	}
	else //동일한 key는 허용하지 않음
	{
		(node->key2).TrashPrice2 = (node->key2).TrashPrice2 + key2.TrashPrice2;
		(node->key2).TrashQuantity2 = (node->key2).TrashQuantity2 + key2.TrashQuantity2;
		return node;
	}
	//균형 인수 재계산
	int balance = get_balance2(node);

	//LL type (왼쪽으로 꺾여있는 타입)
	if (balance > 1 && key2.TrashType2 < node->left->key2.TrashType2)
	{
		return rotate_right2(node); //오른쪽으로 1번 회전
	}
	//RR type (오른쪽으로 꺾여있는 타입)
	if (balance < -1 && key2.TrashType2 > node->right->key2.TrashType2)
	{
		return rotate_left2(node); //왼쪽으로 1번 회전
	}
	//LR type (왼쪽 1번, 오른쪽 1번 꺾여있는 지그재그 타입)
	if (balance > 1 && key2.TrashType2 > node->left->key2.TrashType2)
	{
		node->left = rotate_left2(node->left);
		return rotate_right2(node); //왼쪽으로 1번 회전 -> 오른쪽으로 1번 회전
	}
	//RL type (오른쪽 1번, 왼쪽 1번 꺾여있는 지그재그 타입)
	if (balance < -1 && key2.TrashType2 < node->right->key2.TrashType2)
	{
		node->right = rotate_right2(node->right);
		return rotate_left2(node); //오른쪽으로 1번 회전 -> 왼쪽으로 1번 회전
	}
	return node;

}

//전위 순회 함수
void preorder(AVLNode* root)
{
	if (root != NULL)
	{
		cout << root->key.Name << " "; //key
		preorder(root->left); //왼쪽 subtree
		preorder(root->right); //오른쪽 subtree
	}
}
void preorder2(AVLNode2* root2)
{
	if (root2 != NULL)
	{
		cout << root2->key2.TrashType2 << " " << root2->key2.TrashPrice2 /root2->key2.TrashQuantity2<< endl; //key
		preorder2(root2->left); //왼쪽 subtree
		preorder2(root2->right); //오른쪽 subtree
	}
}
//row로 받아와서 split 함수

int main(void)
{
	string row;
	string row2;
	AVLNode* root = NULL;
	AVLNode2* root2 = NULL;
	fstream fs;
	fs.open("Example_data.csv");
	for (int i = 0; i < 104; i++)
	{
		fs >> row;
		if (i == 0)
		{
			continue;
		}
		Trash t(row);
		root = insert(root, t);
	}
	cout << "전위 순회 결과 " << endl;
	preorder(root);
	cout << "\n";

	fstream fs2;
	fs2.open("Example_data.csv");
	for (int j = 0; j < 104; j++)
	{
		fs2 >> row2;
		if (j == 0)
		{
			continue;
		}
		Trash2 t2(row2);
		root2 = insert2(root2, t2);
	}
	cout << "전위 순회 결과2 " << endl;
	preorder2(root2);

	//root = insert(root, 10); //key 10의 노드 삽입
	//root = insert(root, 20); //key 20의 노드 삽입
	//root = insert(root, 30); //key 30의 노드 삽입
	//root = insert(root, 40); //key 40의 노드 삽입
	//root = insert(root, 50); //key 50의 노드 삽입
	//root = insert(root, 29); //key 29의 노드 삽입

	//cout << "전위 순회 결과 " << endl;
	//preorder(root);
	return 0;

}