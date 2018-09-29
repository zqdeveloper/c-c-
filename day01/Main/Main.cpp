#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS//vs不建议使用传统函数库，如果不用这个宏，会出现一个错，编号c4996
#include <iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
template<class T>
class Person {
public:
	Person(T t) {
		this->t = t;
	}
	void print() {
		cout << "this t value is " << t << endl;
	}
	~Person(){
		cout << "执行了析构函数" << endl;
	}
private:
	T t;
};
int calculator(int a, int b);
template<typename T>
T calculator(T t1, T t2);
template <typename T>
void printArray(T array[], int len);
template <typename T>
int sortArray(T array[], int len);
int test();
int test2();
int test3();
int test4();
typedef struct People
{
	char name[64];
	int age;
}people;
int main(){
	int result;
	//result= test();
	//result = test2();
	//result = test3();
	result = test4();
	return result;
}
int test(){
	int  numbers[] = { 1,2,3,4,5,6,7,8,9,10,12,11,45,23,67,25 };
	int length = sizeof(numbers) / sizeof(int);
	printArray(numbers, length);
	int result = sortArray(numbers, length);
	printArray(numbers, length);
	cout << "------------------------------------------------" << endl;
	cout << result << endl;
	int a = 10;
	int b = 20;
	result = calculator<>(a, b);
	cout << "result=" << result << endl;
	Person<string> *person = new Person<string>("小三");
	person->print();
	delete person;
	return 0;
}
int test2()
{
	int a = 0;
	scanf("%d", &a);
	cout << a << endl;
	return 0;
}
int test3() {
	people people1 = { "张三",12 };
	cout << people1.name << " " << people1.age << endl;
	typedef char * pchar;
	pchar p1, p2;
	cout << typeid(p1).name() << "  " << typeid(p2).name();
	return 0;
}
template<typename T>
void printArray(T array[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		cout << array[i] << "  ";
	}
	cout << "\t------------------------------------------------" << endl;
}
template<typename T>
int  sortArray(T array[], int len) {
	int ret = 0;
	int i, j, temp;
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return ret;
}
template<typename T>
T calculator(T t1, T t2) {
	cout << "this is template" << endl;
	return t1 + t2;
}
int calculator(int a, int b) {
	cout << "this is 普通方法" << endl;
	return a + b;
}
int test4() {
	//1.void:无类型不可以创建变量,无法分配内存
	//2.可以限定函数的返回值
	//3.限定函数的参数列表
	//4.void * 万能指针
	void *a=NULL;
	int b = 20;
	a = &b;
	cout << *(static_cast<int*>(a)) << endl;
	return 0;
}