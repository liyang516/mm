#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

//strcpy函数
char *Strcpy(char *dest, const char *src)
{
	assert(NULL!=dest && NULL!=src);
	char *addr = dest;
	while((*dest++=*src++)!='\0')
		NULL;
	return addr;
}

//strlen函数
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

//strcmp函数
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

//strcat函数
char *Strcat(char *dest, const char *src)
{
	if(dest==NULL || src==NULL)
		return NULL;
	char *addr = dest;
	while(*dest!='\0')
		++dest;
	while((*dest++=*src++)!='\0')
		NULL;
	return addr;
}

//memcpy函数
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

//memset函数
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

// 字符串转换成整数
int atoi(const char *str)
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
		else
		{
			result = result*10 + (*str-'0');
		}
		str++;
	}
	if(*addr == '-')
		result = -result;

	return result; 
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}