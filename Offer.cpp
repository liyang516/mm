#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
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


int main(int argc, char const *argv[])
{
	/* code */
	int Push[5] = {1,2,3,4,5};
	// int Pop[] = {4,5,3,2,1};
	int Pop[5] = {4,3,5,1,2};
	cout<<IsPopOrder(Push,Pop,5)<<endl;
	// char str[] = "I am a student.";
	// char str2[] = "1234567";
	// ReverseSentence(str);
	// LeftRotateString(str2,2);
	// cout<<str<<endl;
	// cout<<str2<<endl;
	return 0;
}