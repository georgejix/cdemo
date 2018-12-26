#include <iostream>
#include "myString.h"
using namespace std;

MyString::MyString(){
	str = new char(1);
	*str = '\0';
	length = 0;
	cout<<"MyString()"<<endl;
}
MyString::~MyString(){

}
