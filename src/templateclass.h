/*
 * templateclass.h
 *
 *  Created on: 2019年1月7日
 *      Author: Administrator
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef SRC_TEMPLATECLASS_H_
#define SRC_TEMPLATECLASS_H_

//类模板
template <class T> class templateclass {
private:
	T a;
	int b;
public:
	templateclass(T a, int b){
		this->a = a;
		this->b = b;
	};
	void show(){
		cout<<this->a<<this->b<<endl;
	}
};

//函数模板
//模板类不支持分离编译，定义和声明需写在一起
template <class T> void display(T *a, int length){
	for(int i = 0; i < length; i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
};
#endif /* SRC_TEMPLATECLASS_H_ */
