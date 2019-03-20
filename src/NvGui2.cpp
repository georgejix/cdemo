#include "NvGui2.h"

#include <iostream>
#include <string>
using namespace std;

NvGui2 *n = NULL;
NvGui2::NvGui2(std::string name){
	this->name = name;
}
NvGui2 *NvGui2::getObject(){
	if(NULL==n){
		n = new NvGui2("name");
	}
	return n;
}
void NvGui2::show(){
	std::cout<<this->name<<std::endl;
}
void NvGui2::setName(string name){
	this->name = name;
}
