#include <iostream>
#include <string>
#include "FuShu.h"
using namespace std;

FuShu::FuShu(int real, int image){
	this->real = real;
	this->image = image;
};
void FuShu::show(){
	cout<<this->real<<"+"<<this->image<<"i"<<endl;
};
/*FuShu FuShu::operator+(FuShu &f1){
    FuShu f(0, 0);
	f.real = this->real + f1.real;
	f.image = this->image + f1.image;
	return f;
};*/
FuShu operator+(FuShu &f1, FuShu &f2){
	FuShu f(0, 0);
	f.real = f1.real + f2.real;
	f.image = f1.image + f2.image;
	return f;
};
bool FuShu::operator==(FuShu &f1){
	bool b = false;
	if(this->real == f1.real && this->image == f1.image){
		b = true;
	}
	return b;
};

FuShu& FuShu::operator+(int i){
	cout<<"+ int"<<endl;
	this->real += i;
	return *this;
};
FuShu& FuShu::operator++(){
	cout<<"前置++"<<endl;
	this->real +=1;
	this->image +=1;
	return *this;
};
FuShu& FuShu::operator++(int k){
	cout<<"后置++"<<endl;
	this->real +=1;
	this->image +=1;
	return *this;
};
/*void operator+(FuShu &f1){
	cout<<"+ FuShu"<<endl;
};*/
void FuShu::operator +(){
	cout<<"+ FuShu"<<endl;
}
