#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;


// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
int FindDuplicaNum(int a[], int length)
{
	if(NULL==a || length<=0)
		return -1;

	for(int i=0;i<length;i++)
	{
		if(a[i]<0 || a[i]>length-1)
			return -1; 
	}

	for(int i=0;i<length;i++)
	{
		while(a[i]!=i)
		{
			if(a[i]==a[a[i]])
				return a[i];
			int temp = a[i];
			a[i] = a[temp];
			a[temp] = temp;
		}
	}

	return -1;

}

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。
int countRange(int a[], int length, int start, int end)
{
	if(a==NULL)
		return -1;
	int count = 0;
	for(int i=0;i<length;i++)
	{
		if(a[i]>=start && a[i]<=end)
			++count;
	}
	return count;
}


int FindDuplicaNumNoModifyArray(int a[], int length)
{
	if(a==NULL||length<=0)
		return -1;
	for(int i=0;i<length;i++)
	{
		if(a[i]<1 || a[i]>length-1)
			return -1;
	}

	int start = 1;
	int end = length-1;
	while(end>=start)
	{
		int mid = (start+end)/2;
		int count = countRange(a,length,start,mid);
		if(start==end)
		{
			if(count>1)
				return start;
			else
				break;
		}
		if(count>mid-start+1)
			end = mid;
		else
			start = mid+1;
	}
	return -1;

}

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
bool FindNumInMatrix(int a[], int rows, int columns, int num)
{
	if(a==NULL || rows<=0 || columns<=0)
		return false;
	for(int row=0,column=columns-1;row<rows,column>=0;)
	{
		if(a[row*rows + column]==num)
			return true;
		else if(a[row*rows + column]>num)
			--column;
		else
			++row;
	}
	return false;
}

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
void ReplaceSpace(char a[], int strSize)
{
	if(a==NULL || strSize<=0)
		return;
	int spaceCount = 0;
	int length = strlen(a);
	for(int i=0;i<length;i++)
	{
		if(a[i]==' ')
			spaceCount++;
	}
	int newLen = length+2*spaceCount;
	if(newLen>strSize)
		return;
	for(;length>=0,newLen>=0;)
	{
		if(a[length]!=' ')
			a[newLen--] = a[length--];
		else
		{
			a[newLen--] = '0';
			a[newLen--] = '2';
			a[newLen--] = '%';
			length--;
		}
	}
}


// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。
void Reverse(char *begin, char *end)
{
	if(begin==NULL || end==NULL)
		return;
	while(begin<end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		--end,++begin;
	}
}

void ReverseSentence(char *sentence)
{
	if(sentence == NULL)
		return;
	char *begin = sentence;
	char *end = sentence;
	while(*end!='\0')
		++end;
	--end;
	Reverse(begin, end);

	begin = end = sentence;

	while(*begin!='\0')
	{
		if(*begin == ' ')
		{
			begin++;
			end++;
		}

		else if(*end==' ' || *end=='\0')
		{
			Reverse(begin,--end);//end为空格时,先将end--, 在Reverse

			begin = ++end;//Reverse后将begin和end都指向空格
		}
		
		else
			end++;
	}
}

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。
void LeftRotateString(char *str, int n)
{
	if(str!=NULL)
	{
		int length = strlen(str);
		if(length>0 && n>0 && n<length)
		{
			char *firstStart = str;
			char *firstEnd = str+n-1;
			char *secondStart = str+n;
			char *secondEnd = str+length-1;

			Reverse(firstStart,firstEnd);
			Reverse(secondStart,secondEnd);
			Reverse(firstStart,secondEnd);
		}
	}
}


// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。
bool IsPopOrder(const int *Push, const int *Pop, int length)
{
	int result = false;

	if(Push!=NULL && Pop!=NULL && length>0)
	{
		const int *tmpPush = Push;
		const int *tmpPop = Pop;
		stack<int> stackData;
		while(tmpPop - Pop<length)
		{
			while(stackData.empty() || stackData.top() != *tmpPop)
			{
				if(tmpPush-Push == length)
					break;
				stackData.push(*tmpPush);
				tmpPush++;
			}

			if(stackData.top() != *tmpPop)
				break;
			stackData.pop();
			tmpPop++;
		}

		if(stackData.empty() && tmpPop-Pop==length)
			result = true;
	}

	return result;
}

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
long FibonacciRecursive(unsigned int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	return FibonacciRecursive(n-1) + FibonacciRecursive(n-2);
}

long Fibonacci(unsigned int n)
{
	int result[] = {0,1};
	if(n<2)
		return result[n];
	long num1 = 0;
	long num2 = 1;
	long FibN = 0;
	for(int i=2;i<=n;i++)
	{
		FibN = num1 + num2;
		num1 = num2;
		num2 = FibN;
	}
	return FibN;
}

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
int getMaxProduct(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;
	int timesOf3 = length/3;
	if(length - timesOf3*3==1)
		timesOf3--;
	int timesOf2 = (length - timesOf3*3)/2;

	return pow(3,timesOf3) * pow(2,timesOf2);
}



// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
bool equal(double a, double b)
{
	if(a-b>-0.0000001 && a-b<0.0000001)
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for(int i=1;i<=exponent;i++)
		result *= base;
	return result;
}

double Power(double base, int exponent)
{
	double result = 0.0;
	if(equal(base,0.0) && exponent<0)
	{
		cout<<"input para is error"<<endl;
		return 0.0;
	}
	unsigned int absExponent;
	if(exponent<0)
		absExponent = (unsigned int)(-exponent);
	else
		absExponent = (unsigned int)(exponent);

	result = PowerWithUnsignedExponent(base, absExponent);
	if(exponent<0)
		result = 1.0/result;
	return result;
}


int main(int argc, char const *argv[])
{
	/* code */
	char str[200] = "We are happy.";
	cout<<str<<endl;
	ReplaceSpace(str,200);
	cout<<str<<endl;
	// int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	// cout<<FindNumInMatrix((int*)matrix, 4,4,22)<<endl;
	// int a[] = {2, 3, 1, 0, 2, 5, 3};
	// cout<<FindDuplicaNum(a,7)<<endl;
	// int a[] =  {2, 3, 5, 4, 3, 2, 6, 7};
	// cout<<FindDuplicaNumNoModifyArray(a,8)<<endl;

	// int Push[5] = {1,2,3,4,5};
	// int Pop[] = {4,5,3,2,1};
	// int Pop[5] = {4,3,5,1,2};
	// cout<<IsPopOrder(Push,Pop,5)<<endl;
	// char str[] = "I am a student.";
	// char str2[] = "1234567";
	// ReverseSentence(str);
	// LeftRotateString(str2,2);
	// cout<<str<<endl;
	// cout<<str2<<endl;

	// cout<<Power(2.0,0)<<endl;
	return 0;
}