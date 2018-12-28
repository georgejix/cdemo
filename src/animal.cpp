#include <iostream>
#include <string>
#include "animal.h"
using namespace std;

Animal::Animal(){

}
Animal::Animal(string name, int age){
	this->name = name;
	this->age = age;
}
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
Animal::~Animal(){
	//cout<<"~Animal()"<<endl;
}
void Animal::getTag(){
	cout<<"动物"<<endl;
};

Bird::Bird(string name, int age, int weight):Animal(name, age){
	this->weight = weight;
}
void Bird::setWeight(int weight){
	this->weight = weight;
};
int Bird::getWeight(){
	return this->weight;
};
void Bird::show(){
	Animal::show();
	cout<<",weight="<<this->weight<<endl;
};
Bird::~Bird(){
	//cout<<"~Bird()"<<endl;
}
void Bird::getTag(){
	cout<<"鸟"<<endl;
};

void Fish::getTag(){
	cout<<"鱼"<<endl;
}

void People::like(Animal& animal){
	cout<<"people like";
	animal.getTag();
}
