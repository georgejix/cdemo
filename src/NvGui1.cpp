#include "NvGui1.h"

#include <iostream>
#include <string>

using namespace std;

NvGui::NvGui()
:age(12){}
NvGui::NvGui(string name, int age, string address)
:name(name)
,age(age)
,address(address){
}
NvGui::~NvGui(){
	//析构函数，对象回收之前被自动调用
	cout<<this->name<<"~nvGui();"<<endl;
}
void NvGui::setName(string name){
		this->name = name;
	}
void NvGui::setAge(int age){
	this->age = age;
}
void NvGui::setAddress(string address){
	this->address = address;
}
string NvGui::getName(){
	return name;
}
int NvGui::getAge(){
	return age;
}
string NvGui::getAddress(){
	return address;
}
NvGui& NvGui::show(){
	cout<<this->name<<"-"<<this->age<<"-"<<this->address<<endl;
	return *this;
}

//传指针
void setParams(NvGui *nv, string name, int age, string address){
	nv->setName(name);
	nv->setAge(age);
	nv->setAddress(address);
}
void printNvGui(NvGui *nv){
	cout<<nv->getName()<<"-"<<nv->getAge()<<"-"<<nv->getAddress()<<endl;
}
//传引用
void setParams(NvGui &nv, string name, int age, string address){
	nv.setName(name);
	nv.setAge(age);
	nv.setAddress(address);
}
void printNvGui(NvGui &nv){
	cout<<nv.getName()<<"-"<<nv.getAge()<<"-"<<nv.getAddress()<<endl;
}
void getObject(NvGui *p){
	NvGui *m = new NvGui("n1", 22, "a1");
	*p = *m;
	delete m;
}
