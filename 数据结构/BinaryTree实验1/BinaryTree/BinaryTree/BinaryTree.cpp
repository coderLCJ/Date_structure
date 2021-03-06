// BinaryTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
namespace ds
{
	struct BinaryTreeNode
	{
		int data;
		struct BinaryTreeNode* left_child;
		struct BinaryTreeNode* right_child;
	};

	using BinaryTree = BinaryTreeNode;

	//先序创建二叉树
	void Create(BinaryTree** T)
	{
		int ch;
		cin >> ch;
		if (ch == -1) { *T = nullptr;		return; }
		else
		{
			*T = new BinaryTree;
			(*T)->data = ch;
			cout << "输入" << ch << "的左子节点:";
			Create(&((*T)->left_child));
			cout << "输入" << ch << "的右子节点:";
			Create((&(*T)->right_child));
		}
	}

	//先序遍历二叉树
	void PreOrder(BinaryTree *T)
	{
		if (T == nullptr) { return; }
		else
		{
			cout << T->data << " ";
			PreOrder(T->left_child);
			PreOrder(T->right_child);
		}
	}

	//中序遍历二叉树
	void InOrder(BinaryTree *T)
	{
		if (T == nullptr) { return; }
		else
		{
			InOrder(T->left_child);
			cout << T->data << " ";
			InOrder(T->right_child);
		}
	}

	//后续遍历二叉树
	void PostOrder(BinaryTree *T)
	{
		if (T == nullptr) { return; }
		else
		{
			PostOrder(T->left_child);
			PostOrder(T->right_child);
			cout << T->data << " ";
		}
	}

	//二叉树的深度
	int Deep(BinaryTree* T)
	{
		int deep = 0;
		if (T != nullptr)
		{
			int leftdeep = Deep(T->left_child);
			int rightdeep = Deep(T->right_child);
			deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
		}

		return deep;
	}

	//叶子节点个数
	int LeafCount(BinaryTree* T)
	{
		static int count;
		if (T != nullptr)
		{
			if (T->left_child == nullptr && T->right_child == nullptr)	count++;
			LeafCount(T->left_child);
			LeafCount(T->right_child);
		}
		return count;
	}

}


//主函数
int main()
{
	ds::BinaryTree* T;
	int depth, leafCount = 0;
	cout << "请输入第一个节点的值，-1表示没有叶节点：" << endl;
	Create(&T);

	cout << "先序遍历二叉树：";
	PreOrder(T);
	cout << endl;

	cout << "中序遍历二叉树：";
	InOrder(T);
	cout << endl;

	cout << "后续遍历二叉树：";
	PostOrder(T);
	cout << endl;

	depth = Deep(T);
	cout << "树的深度为：" << depth << endl;

	leafCount = LeafCount(T);
	cout << "叶子节点个数:" << leafCount << endl;

	system("PAUSE");

	return 0;
}