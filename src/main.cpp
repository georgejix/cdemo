#include <iostream>
#include <string>
#include "nvGui1.h"
#include "nvGui2.h"
#include "fuShu.h"
#include "myString.h"

using namespace std;
void testNvGui1();
void testNvGui2();
void testFuShu();
void testMyString();

int main(){
	//testNvGui1();
	//testNvGui2();
	//testFuShu();
	testMyString();
	return 0;
}

void testMyString(){
	MyString mString;
}
void testFuShu(){
	FuShu *f1 = new FuShu(1, 2);
	FuShu *f2 = new FuShu(2, 3);
	FuShu f3 = (*f1)+(*f2);
	//f1->operator +(*f2);
	//operator +(*f1, *f2);
	f1->show();
	f2->show();
	f3.show();
	if(*f1 == *f2){
		cout<<"相等"<<endl;
	}else{
		cout<<"不相等"<<endl;
	}
	(*f2) + 5;
	f2->show();
	(*f2)++;
	f2->show();
	++(*f2);
	f2->show();
}

void testNvGui2(){
	NvGui2 *NvGui7 = NvGui2::getObject();
	NvGui2 *NvGui8 = NvGui2::getObject();
	cout<<NvGui7<<"---"<<NvGui8<<endl;
	NvGui8->setName("s;");
	NvGui7->show();
}

void testNvGui1(){
	//用new的是堆对象，没有的是栈对象
	//栈对象
	NvGui nv1;
	nv1.setName("李四1");
	nv1.setAge(18);
	nv1.setAddress("新街口");
	cout<<nv1.getName()<<"-"<<nv1.getAge()<<"-"<<nv1.getAddress()<<endl;

	//堆对象
	NvGui *nv2 = NULL;
	nv2 = new NvGui();
	nv2->setName("李四2");
	nv2->setAge(18);
	nv2->setAddress("新街口");
	cout<<nv2->getName()<<"-"<<nv2->getAge()<<"-"<<nv2->getAddress()<<endl;
	//free(nv2);
	delete nv2;

	NvGui NvGui3;
	setParams(&NvGui3, "张三3", 19, "珠江路");
	printNvGui(&NvGui3);
	setParams(NvGui3, "张五3", 139, "珠江路");
	printNvGui(NvGui3);
	NvGui3.show().show();

	NvGui *NvGui4 = new NvGui("吴菊4", 22, "广西");
	NvGui4->show();
	delete NvGui4;

	NvGui *NvGui5 = new NvGui();
	NvGui5->show();
	delete NvGui5;

	NvGui *NvGui6 = new NvGui();
	getObject(NvGui6);
	NvGui6->show();
}
