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
	nvGui& show();
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
//传指针
void setParams(nvGui *nv, string name, int age, string address){
	nv->setName(name);
	nv->setAge(age);
	nv->setAddress(address);
}
void printNvGui(nvGui *nv){
	cout<<nv->getName()<<"-"<<nv->getAge()<<"-"<<nv->getAddress()<<endl;
}
//传引用
void setParams(nvGui &nv, string name, int age, string address){
	nv.setName(name);
	nv.setAge(age);
	nv.setAddress(address);
}
void printNvGui(nvGui &nv){
	cout<<nv.getName()<<"-"<<nv.getAge()<<"-"<<nv.getAddress()<<endl;
}
nvGui& nvGui::show(){
	cout<<this->name<<"-"<<this->age<<"-"<<this->address<<endl;
	return *this;
}
int main(){

    //用new的是堆对象，没有的是栈对象
    //栈对象
    nvGui nv1;
	nv1.setName("李四");
	nv1.setAge(18);
	nv1.setAddress("新街口");
	cout<<nv1.getName()<<"-"<<nv1.getAge()<<"-"<<nv1.getAddress()<<endl;

	//堆对象
	nvGui *nv2 = NULL;
	nv2 = new nvGui();
	nv2->setName("李四");
	nv2->setAge(18);
	nv2->setAddress("新街口");
	cout<<nv2->getName()<<"-"<<nv2->getAge()<<"-"<<nv2->getAddress()<<endl;
	free(nv2);

	nvGui nvGui3;
	setParams(&nvGui3, "张三", 19, "珠江路");
	printNvGui(&nvGui3);
	setParams(nvGui3, "张五", 139, "珠江路");
	printNvGui(nvGui3);
	nvGui3.show().show();
	return 0;
}
