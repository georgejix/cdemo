#include <iostream>
#include <string>
#include "animal.h"
using namespace std;

void Animal::setName(string name){
	this->name = name;
};
void Animal::setAge(int age){
	this->age = age;
};
string Animal::getName(){
	return this->name;
};
int Animal::getAge(){
	return this->age;
};
void Animal::show(){
	cout<<"name="<<this->name<<",age="<<this->age<<endl;
};

Bird::Bird(string name, int age){
	this->setName(name);
	this->setAge(age);
}
void Bird::setWeight(int weight){
	this->weight = weight;
};
int Bird::getWeight(){
	return this->weight;
};
