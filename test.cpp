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

class A{
public:
	A(){cout<<"A"<<endl;}
	~A(){cout<<"~A"<<endl;}
};

class B:public A{
public:
	B(){cout<<"B"<<endl;}
	~B(){cout<<"~B"<<endl;}
};



int main(int argc, char const *argv[])
{
	/* code */
	B b;

	return 0;
}