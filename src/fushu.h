#include <iostream>
#include <string>
using namespace std;

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
};
FuShu operator+(FuShu &f1, FuShu &f2);
