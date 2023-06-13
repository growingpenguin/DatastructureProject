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
	vector <string> result; //������ �������� ����� ���ڿ��� ���

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


//������ ȸ�� 
AVLNode* rotate_right(AVLNode* parent)
{
	AVLNode* child = parent->left; //���� ����Ʈ���� ��Ʈ ����� ���� �ڽ��� child ���� ����
	parent->left = child->right; //������ ȸ��
	child->right = parent; //1.child��尡 ����Ʈ���� ��Ʈ��尡 ��, 2.parent��尡 child����� ������ �ڽĳ�尡 �� 

	return child; //���ο� ��Ʈ ��ȯ
}
AVLNode2* rotate_right2(AVLNode2* parent)
{
	AVLNode2* child = parent->left; //���� ����Ʈ���� ��Ʈ ����� ���� �ڽ��� child ���� ����
	parent->left = child->right; //������ ȸ��
	child->right = parent; //1.child��尡 ����Ʈ���� ��Ʈ��尡 ��, 2.parent��尡 child����� ������ �ڽĳ�尡 �� 

	return child; //���ο� ��Ʈ ��ȯ
}


//���� ȸ�� 
AVLNode* rotate_left(AVLNode* parent)
{
	AVLNode* child = parent->right; //���� ����Ʈ���� ��Ʈ ����� ������ �ڽ��� child ���� ����
	parent->right = child->left; //���� ȸ��
	child->left = parent; //1.child��尡 ����Ʈ���� ��Ʈ��尡 ��, 2.parent��尡 child����� ���� �ڽĳ�尡 ��

	return child;
}
AVLNode2* rotate_left2(AVLNode2* parent)
{
	AVLNode2* child = parent->right; //���� ����Ʈ���� ��Ʈ ����� ������ �ڽ��� child ���� ����
	parent->right = child->left; //���� ȸ��
	child->left = parent; //1.child��尡 ����Ʈ���� ��Ʈ��尡 ��, 2.parent��尡 child����� ���� �ڽĳ�尡 ��

	return child;
}


//���� 
int get_height(AVLNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right)); //���� ����Ʈ�� ������ ����Ʈ�� �� �� ���� ���̰� Ʈ���� ���̰� ��
	}
	return height;
}

//������ �����μ� ���ϱ�
int get_balance(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return get_height(node->left) - get_height(node->right); //���� ����Ʈ�� ���� - ������ ����Ʈ�� ����
}

int get_height2(AVLNode2* node)
{
	int height2 = 0;
	if (node != NULL)
	{
		height2 = 1 + max(get_height2(node->left), get_height2(node->right)); //���� ����Ʈ�� ������ ����Ʈ�� �� �� ���� ���̰� Ʈ���� ���̰� ��
	}
	return height2;
}
int get_balance2(AVLNode2* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return get_height2(node->left) - get_height2(node->right); //���� ����Ʈ�� ���� - ������ ����Ʈ�� ����
}


//��� �߰� �Լ�
//���ο� ��Ʈ ��ȯ
AVLNode* insert(AVLNode* node, Trash key)
{
	if (node == NULL) //���ο� ��� �߰�
	{
		return new AVLNode(key);
	}

	if (key.Name < node->key.Name) //������ ���� ����Ʈ���� 
	{
		node->left = insert(node->left, key);
	}
	else if (key.Name > node->key.Name) //ũ�� ������ ����Ʈ���� 
	{
		node->right = insert(node->right, key);
	}
	else //������ key�� ������� ����
	{
		return node;
	}

	//���� �μ� ����
	int balance = get_balance(node);

	//LL type (�������� �����ִ� Ÿ��)
	if (balance > 1 && key.Name < node->left->key.Name)
	{
		return rotate_right(node); //���������� 1�� ȸ��
	}
	//RR type (���������� �����ִ� Ÿ��)
	if (balance < -1 && key.Name > node->right->key.Name)
	{
		return rotate_left(node); //�������� 1�� ȸ��
	}
	//LR type (���� 1��, ������ 1�� �����ִ� ������� Ÿ��)
	if (balance > 1 && key.Name > node->left->key.Name)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node); //�������� 1�� ȸ�� -> ���������� 1�� ȸ��
	}
	//RL type (������ 1��, ���� 1�� �����ִ� ������� Ÿ��)
	if (balance < -1 && key.Name < node->right->key.Name)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node); //���������� 1�� ȸ�� -> �������� 1�� ȸ��
	}
	return node;
}

AVLNode2* insert2(AVLNode2* node, Trash2 key2)
{
	if (node == NULL) //���ο� ��� �߰�
	{
		return new AVLNode2(key2);
	}
	if (key2.TrashType2 < node->key2.TrashType2) //������ ���� ����Ʈ���� 
	{
		node->left = insert2(node->left, key2);
	}
	else if (key2.TrashType2 > node->key2.TrashType2) //ũ�� ������ ����Ʈ���� 
	{
		node->right = insert2(node->right, key2);
	}
	else //������ key�� ������� ����
	{
		(node->key2).TrashPrice2 = (node->key2).TrashPrice2 + key2.TrashPrice2;
		(node->key2).TrashQuantity2 = (node->key2).TrashQuantity2 + key2.TrashQuantity2;
		return node;
	}
	//���� �μ� ����
	int balance = get_balance2(node);

	//LL type (�������� �����ִ� Ÿ��)
	if (balance > 1 && key2.TrashType2 < node->left->key2.TrashType2)
	{
		return rotate_right2(node); //���������� 1�� ȸ��
	}
	//RR type (���������� �����ִ� Ÿ��)
	if (balance < -1 && key2.TrashType2 > node->right->key2.TrashType2)
	{
		return rotate_left2(node); //�������� 1�� ȸ��
	}
	//LR type (���� 1��, ������ 1�� �����ִ� ������� Ÿ��)
	if (balance > 1 && key2.TrashType2 > node->left->key2.TrashType2)
	{
		node->left = rotate_left2(node->left);
		return rotate_right2(node); //�������� 1�� ȸ�� -> ���������� 1�� ȸ��
	}
	//RL type (������ 1��, ���� 1�� �����ִ� ������� Ÿ��)
	if (balance < -1 && key2.TrashType2 < node->right->key2.TrashType2)
	{
		node->right = rotate_right2(node->right);
		return rotate_left2(node); //���������� 1�� ȸ�� -> �������� 1�� ȸ��
	}
	return node;

}

//���� ��ȸ �Լ�
void preorder(AVLNode* root)
{
	if (root != NULL)
	{
		cout << root->key.Name << " "; //key
		preorder(root->left); //���� subtree
		preorder(root->right); //������ subtree
	}
}
void preorder2(AVLNode2* root2)
{
	if (root2 != NULL)
	{
		cout << root2->key2.TrashType2 << " " << root2->key2.TrashPrice2 /root2->key2.TrashQuantity2<< endl; //key
		preorder2(root2->left); //���� subtree
		preorder2(root2->right); //������ subtree
	}
}
//row�� �޾ƿͼ� split �Լ�

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
	cout << "���� ��ȸ ��� " << endl;
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
	cout << "���� ��ȸ ���2 " << endl;
	preorder2(root2);

	//root = insert(root, 10); //key 10�� ��� ����
	//root = insert(root, 20); //key 20�� ��� ����
	//root = insert(root, 30); //key 30�� ��� ����
	//root = insert(root, 40); //key 40�� ��� ����
	//root = insert(root, 50); //key 50�� ��� ����
	//root = insert(root, 29); //key 29�� ��� ����

	//cout << "���� ��ȸ ��� " << endl;
	//preorder(root);
	return 0;

}