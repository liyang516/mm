#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

//strcpy
char *Strcpy(char *dest, const char *src)
{
	assert(NULL!=dest && NULL!=src);
	char *addr = dest;
	while((*dest++=*src++)!='\0')
		NULL;
	return addr;
}

//strlen
int Strlen(const char *src)
{
	if(NULL==src)
		return -1;
	int len = 0;
	while(*src!='\0')
	{
		++len;
		++src;
	}
	return len;
}

//strcmp
int Strcmp(const char *s1, const char *s2)
{
	assert(NULL!=s1 && NULL!=s2);
	while(s1 && s2 && *s1==*s2)
	{
		++s1;
		++s2;
	}
	return (*s1-*s2);
}

//strcat
char *Strcat(char *dest, const char *src)
{
	if(dest==NULL && src==NULL)
		return NULL;
	char *addr = dest;
	while(*dest!='\0')
		++dest;
	while((*dest++=*src++)!='\0')
		NULL;
	return addr;
}

//memcpy
void *Memcpy(void *dest, const void *src, int count)
{
	if(dest==NULL || src==NULL || count<=0)
		return NULL;
	void *addr = dest;
	while(count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}

	return addr;
}

//memset
void *Memset(void *str, int ch, int count)
{
	if(str==NULL || count<=0)
		return NULL;
	void *addr = str;
	while(count--)
	{
		*(char*)str = (char)ch;
		str = (char*)str + 1;
	}
	return addr;
}

// class string
class String{
public:
	String(const char *str = NULL);
	~String();
	String(const String &rhs);
	String& operator=(const String &rhs);
protected:
private:
	char *m_data;
};

String::String(const char *str)
{
	if(str!=NULL)
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	else
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	cout<<"调用构造函数"<<endl;
}

String::~String()
{
	delete []m_data;
	cout<<"调用析构函数"<<endl;
}

String::String(const String &rhs)
{
	m_data = new char[strlen(rhs.m_data)+1];
	strcpy(m_data, rhs.m_data);
	cout<<"调用拷贝构造函数"<<endl;
}

String& String::operator=(const String &rhs)
{
	cout<<"调用赋值构造函数"<<endl;
	if(this!=&rhs)
	{
		String tempString = rhs;

		char *tmpData = tempString.m_data;
		tempString.m_data = m_data;
		m_data = tmpData;

	}
	return *this;
}

// atoi
int Atoi(const char *str)
{
	assert(NULL!=str);
	int result = 0;
	const char *addr = str;
	if(*str=='+'||*str=='-')
		str++;
	while(*str!='\0')
	{
		if(*str<'0'||*str>'9')
			break;
	
		result = result*10 + (*str-'0');
		str++;
	}
	if(*addr == '-')
		result = -result;

	return result; 
}

// Singleton model
class Singleton{
public:
	static Singleton* GetInstane()
	{
		if(instance==NULL)
			instance = new Singleton();
		return instance;
	}
protected:
private:
	Singleton(){};
	static Singleton *instance;
};

Singleton* Singleton::instance = Singleton::GetInstane();

int main(int argc, char const *argv[])
{
	/* code */
	Singleton *s1 = Singleton::GetInstane();
	Singleton *s2 = Singleton::GetInstane();
	if(s1==s2)
		cout<<"haha"<<endl;
	return 0;
}
