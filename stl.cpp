#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;

template <typename T>
void showvector(vector<T> v)
{
	for(typename vector<T>::iterator it=v.begin();it!=v.end();it++)
	{
		if(it==v.end()-1)
			cout<<*it<<endl;
		else
			cout<<*it<<",";
	}
}

template <typename T>
void showset(set<T> s)
{
	for(typename set<T>::iterator it=s.begin(); it!=s.end(); it++)
	{
		cout<<*it<<",";
	}
	cout<<endl;
}

template <typename T>
void showlist(list<T> l)
{
	for(typename list<T>::iterator it=l.begin(); it!=l.end(); it++)
	{
		cout<<*it<<",";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	
	/*
	*****************************
	         vector demo
	*****************************
	*/
	vector<int> vint(2,123);
	showvector(vint);
	vector<char> vchar(2,'@');
	showvector(vchar);

	/*
	*****************************
	          set demo
	*****************************
	*/
	set<int> sint;
	sint.insert(1);
	sint.insert(2);
	showset(sint);
	cout<<"set size:"<<sint.size()<<endl;

	/*
	*****************************
	          list demo
	*****************************
	*/
	list<int> lint(1,98);
	lint.push_back(99);
	lint.push_front(97);

	showlist(lint);
	cout<<lint.front()<<endl;
	cout<<lint.back()<<endl;
	lint.pop_front();
	lint.pop_back();
	showlist(lint);
	cout<<"list size:"<<lint.size()<<endl;


	/*
	*****************************
	          set demo
	*****************************
	*/
	map<string,int> m1;
	m1["Kobe"] = 100;
    m1["James"] = 99;
    m1["Curry"] = 98;
    string s("Jordan");
    m1[s] = 90;
    m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
    pair<map<string, int>::iterator, bool> result;
    result = m1.insert(pair<string, int>("Kobe", 22));
    if(result.second==true)
    	cout<<"insert success."<<endl;
    else
    	cout<<"insert failed."<<endl;
    cout<<m1["Kobe"]<<endl;
    cout<<"map size:"<<m1.size()<<endl;


	return 0;
}