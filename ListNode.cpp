#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

//链表定义
typedef struct ListNode
{
	int data;
	ListNode *next;
}ListNode;

// 创建链表
ListNode* CreateList(int num)
{
	if(num<=0)
		return NULL;

	ListNode *head = NULL,*s = NULL, *p = NULL;

	for(int i=0;i<num;i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		int tmp_data;
		cin>>tmp_data;
		p->data = tmp_data;
		if(head==NULL)
		{
			head = p;
			s = p;
		}
		else
		{
			s->next = p;
			s = p;
		}
	}
	s->next = NULL;
	return head;
}

// 输出链表
void PrintList(ListNode *head)
{
	if(NULL==head)
		return;
	while(head)
	{
		cout<<head->data;
		head = head->next;
	}
	cout<<endl;
}

// 逆向输出链表,利用栈
void PrintListReverse(ListNode *head)
{
	if(head==NULL)
		return ;

	stack<ListNode*> st;
	while(head!=NULL)
	{
		st.push(head);
		head = head->next;
	}

	while(!st.empty())
	{
		cout<<st.top()->data;
		st.pop();
	}
	cout<<endl;
	return;
}

// 逆向输出链表,利用递归
void PrintListReverseRecursive(ListNode *head)
{
	if(head!=NULL)
	{
		if(head->next!=NULL)
			PrintListReverseRecursive(head->next);
		cout<<head->data;
	}
	// cout<<endl;
	return;
}

// 链表逆序
ListNode* ReverseList(ListNode *head)
{
	ListNode *ReverseHead = NULL;
	ListNode *pNode = head;
	ListNode *pPrev = NULL;
	ListNode *pNext = NULL;

	while(pNode!=NULL)
	{
		pNext = pNode->next;
		if(pNext == NULL)
			ReverseHead = pNode;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return ReverseHead;
}



// 合并两个有序列表
ListNode* MergeList(ListNode *head1, ListNode*head2)
{
	ListNode *head = NULL;
	if(head1==NULL && head2==NULL)
		return NULL;
	if(head1==NULL && head2!=NULL)
		return head2;
	if(head1!=NULL && head2==NULL)
		return head1;
	if(head1->data<head2->data)
	{
		head = head1;
		head->next = MergeList(head1->next,head2);
	}
	else
	{
		head = head2;
		head->next = MergeList(head1,head2->next);
	}
	return head;
}

// 判断链表是否有环儿,有环儿的话返回相遇节点
ListNode* CheckLoop(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
			return fast;
	}
	return NULL;
}


//求链表环儿长度
int LoopLength(ListNode *head)
{
	int length = 0;
	ListNode *slow = head;
	ListNode *fast = head;
	bool again = false;
	bool begin = false;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast && begin==false)
		{
			begin = true;
			again = true;
		}
		if(slow==fast && again==true)
			break;
		if(again==true)
			length++;
	}
	return length;
}

// 求链表环的入口节点
ListNode* EntryNodeOfLoop(ListNode *head)
{
	ListNode *meetNode = CheckLoop(head);
	if(NULL == meetNode)
		return NULL;
	ListNode *pNode1 = meetNode;
	int loopNum = 1;
	
	//先求环的长度
	while(pNode1->next != meetNode)
	{
		++loopNum;
		pNode1 = pNode1->next;
	}

	pNode1 = head;
	for(int i=0;i<loopNum;i++)
		pNode1 = pNode1->next;

	ListNode *pNode2 = head;
	while(pNode1!=pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;

}

// 输出该链表中倒数第k个结点
ListNode* FindKthToTail(ListNode *head, unsigned int k)
{
	if(head==NULL || k<=0)
		return NULL;

	ListNode *pAhead = head;
	ListNode *pBehind = head;

	//先走k-1步
	for(int i=0;i<k-1;i++)
	{
		if(pAhead->next!=NULL)
			pAhead = pAhead->next;
		else
			return NULL;
	}

	while(pAhead->next!=NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;

}

// 给定一个节点，在链表中删除该节点
void DeleteListNode(ListNode **head, ListNode *deleteNode)
{
	if(!head||!deleteNode)
		return;

	// 链表只有一个节点的情况
	if(*head == deleteNode)
	{
		delete deleteNode;
		deleteNode = NULL;
		*head = NULL;
	}

	// 链表有多个节点，删除节点不是链表的最后一个节点
	else if(deleteNode->next!=NULL)
	{
		ListNode *pNext = deleteNode->next;
		deleteNode->data = pNext->data;
		deleteNode->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}

	// 链表有多个节点，删除节点是链表的最后一个节点
	else
	{
		ListNode *pNode = *head;
		while(pNode->next!=deleteNode)
			pNode = pNode->next;
		pNode->next = NULL;
		delete deleteNode;
		deleteNode = NULL;
	}
	return ;
}

// 输入两个链表，找出它们的第一个公共结点
int GetListLength(ListNode *head)
{
	int listLength = 0;
	ListNode *pNode = head;
	while(pNode!=NULL)
	{
		++listLength;
		pNode = pNode->next;
	}
	return listLength;
}

ListNode* FindFirstCommonNode(ListNode *head1, ListNode *head2)
{
	int len1 = GetListLength(head1);
	int len2 = GetListLength(head2);
	int dif = 0;
	ListNode *longHead = NULL;
	ListNode *shortHead = NULL;
	if(len1>len2)
	{
		dif = len1-len2;
		longHead = head1;
		shortHead = head2;
	}
	else
	{	
		dif = len2-len1;
		longHead = head2;
		shortHead = head1;
	}

	for(int i=0;i<dif;i++)
		longHead = longHead->next;
	while(longHead!=NULL  && shortHead!=NULL && longHead!=shortHead)
	{
		longHead = longHead->next;
		shortHead = shortHead->next;
	}


	return longHead;
}


int Add(int a, int b)
{
	int sum,carry;
	do
	{
		sum = a^b;
		carry = (a&b)<<1;
		a = sum;
		b = carry;
	}while(carry!=0);

	return a;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<Add(3,-33)<<endl;
	// ListNode *list = CreateList(5);
	// PrintList(list);
	// ListNode *k = FindKthToTail(list,10);
	// if(k==NULL)
	// 	cout<<"error"<<endl;
	// else
	// 	cout<<k->data<<endl;
	// ListNode *list2 = ReverseList(list);
	// PrintList(list2);
	// PrintList(list);
	// ListNode *list3 = CreateList(5);
	// PrintList(list3);

	// ListNode *head = MergeList(list,list3);
	// PrintList(head);

	return 0;
}