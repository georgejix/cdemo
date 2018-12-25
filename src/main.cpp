#include <iostream>
#include <string>

using namespace std;

class nvGui{
private:
	string name;
	int age;
	string address;
public:
	void setName(string name);
	void setAge(int age);
	void setAddress(string address);
	string getName();
	int getAge();
	string getAddress();
};

void nvGui::setName(string name){
		this->name = name;
	}
void nvGui::setAge(int age){
	this->age = age;
}
void nvGui::setAddress(string address){
	this->address = address;
}
string nvGui::getName(){
	return name;
}
int nvGui::getAge(){
	return age;
}
string nvGui::getAddress(){
	return address;
}

int main(){
/*
    //用new的是堆对象，没有的是栈对象
    //栈对象
    nvGui nv;
	nv.setName("李四");
	nv.setAge(18);
	nv.setAddress("新街口");
	cout<<nv.getName()<<"-"<<nv.getAge()<<"-"<<nv.getAddress()<<endl;*/
	//堆对象
	nvGui *nv = NULL;
	nv = new nvGui();
	nv->setName("李四");
	nv->setAge(18);
	nv->setAddress("新街口");
	cout<<nv->getName()<<"-"<<nv->getAge()<<"-"<<nv->getAddress()<<endl;
	free(nv);
	return 0;
}
