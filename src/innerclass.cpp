/*
 * innerclass.cpp
 *
 *  Created on: 2019年1月7日
 *      Author: Administrator
 */

#include <iostream>
#include <string>
#include "innerclass.h"
using namespace std;


innerclass::innerclass() {
	// TODO Auto-generated constructor stub

}

innerclass::~innerclass() {
	// TODO Auto-generated destructor stub
}

void innerclass::inner::show(){
	cout<<"inner"<<endl;
}

