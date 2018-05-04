#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
	本文件是关于单例模式的4种实现方法：

	1、懒汉式线程不安全

	2、懒汉式线程安全(使用锁)

	3、懒汉式线程安全(内部static变量)

	4、饿汉式线程安全
*/

// 1、懒汉式线程不安全，instance变量不预先定义实现，
//   仅初始化为NULL，只有当使用时才调用GetInstance方法创建实例
//   并且为线程不安全，多线程同时调用GetInstance函数时可能会创建多个实例内存对象
class Singleton1{
private:
	Singleton1(){}
	static Singleton1* instance;
public:
	static Singleton1* getInstance();
};
Singleton1* Singleton1::instance = NULL;
Singleton1* Singleton1::getInstance()
{
	if(instance==NULL)
		instance = new Singleton1();
	return instance;
}

// 2、懒汉式线程安全，instance同样先初始化为NULL不进行实例化(使用锁)
class Singleton2{
private:
	Singleton2(){}
	static Singleton2* instance;
	static pthread_mutex_t mutex;
public:
	static Singleton2* getInstance();
};
pthread_mutex_t Singleton2::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton2* Singleton2::instance = NULL;
Singleton2* Singleton2::getInstance()
{
	if(instance==NULL)
	{
		pthread_mutex_lock(&mutex);
		if(instance==NULL)
			instance = new Singleton2();
		pthread_mutex_unlock(&mutex);
	}
	return instance;
}

// 3、懒汉式线程安全(内部static变量)
class Singleton3{
private:
	Singleton3(){}
	static Singleton3* instance;
	static pthread_mutex_t mutex;
public:
	static Singleton3* getInstance();
};
pthread_mutex_t Singleton3::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton3* Singleton3::instance = NULL;
Singleton3* Singleton3::getInstance()
{
	pthread_mutex_lock(&mutex);
	static Singleton3 obj;
	pthread_mutex_unlock(&mutex);
	return &obj;
}

// 4、饿汉式线程安全，提前将instance实例化(没有需求也提前实例化，用空间换时间)
class Singleton4{
private:
	Singleton4(){}
	static Singleton4* instance;
public:
	static Singleton4* getInstance();
};
Singleton4* Singleton4::instance = new Singleton4();
Singleton4* Singleton4::getInstance()
{
	return instance;
}

int main(int argc, char const *argv[])
{
	/* code */
	Singleton1 *s11 = Singleton1::getInstance();
	Singleton1 *s12 = Singleton1::getInstance();
	cout<<(s11==s12)<<endl;

	Singleton2 *s21 = Singleton2::getInstance();
	Singleton2 *s22 = Singleton2::getInstance();
	cout<<(s21==s22)<<endl;

	Singleton3 *s31 = Singleton3::getInstance();
	Singleton3 *s32 = Singleton3::getInstance();
	cout<<(s31==s32)<<endl;

	Singleton4 *s41 = Singleton4::getInstance();
	Singleton4 *s42 = Singleton4::getInstance();
	cout<<(s41==s42)<<endl;
	return 0;
}