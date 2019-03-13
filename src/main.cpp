#include <iostream>
#include <string>
#include "nvGui1.h"
#include "nvGui2.h"
#include "fuShu.h"
#include "myString.h"
#include "animal.h"
#include "testExtends.h"
#include "innerclass.h"
#include "templateclass.h"
#include <fstream>
#include <vector>
#include "TestLib.h"

using namespace std;
void testNvGui1();
void testNvGui2();
void testFuShu();
void testMyString();
void testAnimal();
void testExtend();
void testFstream();
void testInnerclass();
void testTemplateclass();
void testVector();
void testStaticLib();

int main(){
	cout<<~1<<endl;
	//testNvGui1();
	//testNvGui2();
	//testFuShu();
	//testMyString();
	//testAnimal();
	testExtend();
	//testFstream();
	//testInnerclass();
	//testTemplateclass();
	//testVector();
	//testStaticLib();
	return 0;
}

void testStaticLib(){
	TestLib *t = new TestLib();
	cout<<t->add(3,5)<<endl;
}

template <class T> class templateclass;
void testVector(){
	vector<string> myvector;
	myvector.push_back("ab");
	myvector.push_back("bb");
	myvector.push_back("cb");

	for(size_t i = 0; i < myvector.size(); i++){
		cout<<(myvector[i])<<'\t';
	}
	cout<<endl;

	vector<string>::iterator myiterator;
	for(myiterator = myvector.begin(); myiterator != myvector.end(); myiterator++){
		cout<<*myiterator<<'\t';
	}
	cout<<endl;
	/*vector<string> *myvector = new vector<string>();
	myvector->push_back("ab");
	myvector->push_back("bb");
	myvector->push_back("cb");

	for(int i = 0; i < myvector->size(); i++){
		cout<<*(myvector[i])<<'\t';
	}
	cout<<endl;

	vector<string>::iterator myiterator;
	for(myiterator = myvector->begin(); myiterator != myvector->end(); myiterator++){
		cout<<*myiterator<<'\t';
	}
	cout<<endl;*/
}

void testTemplateclass(){
	double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	display(d, 5);
	int i[] = {1, 2, 3, 4, 5};
	display(i, 5);
	templateclass<string> *t = new templateclass<string>("ssssss", 25);
	t->show();
	delete t;
}

void testInnerclass(){
	innerclass::inner *inner = new innerclass::inner();
	inner->show();
	delete inner;
}

void testFstream(){
	string filepath = "E://work_jx/wenjian/20190102/1.txt";
	ofstream fout(filepath.c_str());
	fout << "testfstreams" << endl;
	fout.close();

	ifstream fin(filepath.c_str());
	string s;
	fin>>s;
	cout.width(50);
	cout.fill('*');
	cout<<left;
	cout<<s<<endl;
	fin.close();
}

void testExtend(){
	AnimalOfLiangqi lq;
	lq.getAge();
}

void testAnimal(){
	Bird *bird = new Bird("pigeon", 12, 5);
	bird->show();
	cout<<"weight="<<bird->getWeight()<<endl;

	Animal animal;
	Fish fish;
	People::like(fish);
	People::like(*bird);
	People::like(animal);

	cout<<"-----"<<endl;
	Animal *animal_ = NULL;
	animal_ = &animal;
	animal_->getTag();
	animal_ = bird;
	animal_->getTag();
	animal_ = &fish;
	animal_->getTag();

	Bird *b = NULL;
	b = (Bird*) &animal;
	//去掉父类中方法前virtual，会直接执行子类方法
	b->getTag();

	delete bird;
}

void testMyString(){
	MyString s1 = "string";
	//MyString *mString = new MyString("string");
	cout<<s1<<" size="<<s1.size()<<endl;
	s1[2] = 'm';
	cout<<s1<<endl;

	MyString s2 = "abcdefg";
	MyString s3;
	s3 = s1 + s2;
	cout<<s3<<endl;

	cout<<s1(1)<<endl;
	if(s1 == s2){
		cout<<"相等"<<endl;
	}else{
		cout<<"不相等"<<endl;
	}
	cout<<s2.find('p')<<endl;
	MyString s4;
	cout<<s4.isEmpty()<<endl;

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
	+(*f1);

	delete f1;
	delete f2;
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
