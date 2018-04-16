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

	cout<<Power(2.0,0)<<endl;
	return 0;
}