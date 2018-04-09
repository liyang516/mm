#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//二叉树节点定义
typedef struct BiTNode{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode;

//创建二叉树
void CreateBiTree(BiTNode* &Tree)
{
	char ch;
	cin>>ch;
	if(ch == '#')
		Tree = NULL;
	else
	{
		Tree = new BiTNode;
		Tree->data = ch;
		CreateBiTree(Tree->lchild);
		CreateBiTree(Tree->rchild);
	}
}

//前序遍历
void PreOrder(BiTNode *Tree)
{
	if(Tree==NULL)
		return;
	cout<<Tree->data;
	PreOrder(Tree->lchild);
	PreOrder(Tree->rchild);
}

//中序遍历
void InOrder(BiTNode *Tree)
{
	if(Tree==NULL)
		return;
	InOrder(Tree->lchild);
	cout<<Tree->data;
	InOrder(Tree->rchild);
}

//后序遍历
void LastOrder(BiTNode *Tree)
{
	if(Tree==NULL)
		return;
	LastOrder(Tree->lchild);
	LastOrder(Tree->rchild);
	cout<<Tree->data;
}

//二叉树高度/深度
int BiTreeHeight(BiTNode *Tree)
{
	if(Tree == NULL)
		return 0;
	int left = BiTreeHeight(Tree->lchild);
	int right = BiTreeHeight(Tree->rchild);
	return (left>right)?(left+1):(right+1);
}

// 二叉树层序遍历,利用队列(FIFO原则),先将根节点push,然后依次push根节点的左右节点,然后队列pop
void BFS(BiTNode *Tree)
{
	if(Tree==NULL)
		return ;
	queue<BiTNode*> queueTree;
	queueTree.push(Tree);
	BiTNode *pNode;
	while(!queueTree.empty())
	{
		*pNode = queueTree.front();
		cout<<pNode->data;
		if(pNode->lchild!=NULL)
			queueTree.push(pNode->lchild);
		if(pNode->rchild!=NULL)
			queueTree.push(pNode->rchild);
		queueTree.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	BiTNode *Tree;
	CreateBiTree(Tree);
	PreOrder(Tree);
	cout<<endl;
	InOrder(Tree);
	cout<<endl;
	LastOrder(Tree);
	cout<<endl;
	cout<<BiTreeHeight(Tree)<<endl;
	BFS(Tree);
	return 0;
}