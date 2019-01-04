#include <iostream>
#include <string>
using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
private:
	string name;
	int age;
public:
	Animal();
	Animal(string name, int age);
	void setName(string name);
	void setAge(int age);
	string getName();
	int getAge();
public:
	void show();
	virtual ~Animal();
	//虚函数是指一个类中你希望重载的成员函数 ，
	//当你用一个  基类指针或引用   指向一个继承
	//类对象的时候，调用一个虚函数时, 实际调用
	//的是继承类的版本。
	virtual void getTag();
};

class Bird : public Animal{
private:
	int weight;
public:
	Bird(string name, int age, int weight);
	void setWeight(int weight);
	int getWeight();
	void show();
	~Bird();
	void getTag();
};

class Fish : public Animal{
public:
	void getTag();
};

class People{
public:
static void like(Animal& animal);
};

#endif
