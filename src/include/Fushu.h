#include <iostream>
#include <string>
using namespace std;

#ifndef FUSHU_H
#define FUSHU_H

class FuShu{
	private:
		int real;
		int image;
	public:
		FuShu(int real, int image);
		void show();
		//fushu operator+(fushu &f);
		friend FuShu operator+(FuShu &f1, FuShu &f2);
		bool operator==(FuShu &f1);
		FuShu& operator+(int i);
		FuShu& operator++();
		FuShu& operator++(int k);
		void operator+();//和独立函数void operator+(FuShu &f1);等价
};
FuShu operator+(FuShu &f1, FuShu &f2);
//void operator+(FuShu &f1);

#endif
