#include <iostream>
using namespace std;

#ifndef MYSTRING_H
#define MYSTRING_H

class MyString{
private:
	int length;
	char *str;
	int getLength(const char *p);
public:
	MyString();
	MyString(const char *p);
	MyString(int l);
	~MyString();
	int size();
	void print();
	friend ostream& operator<<(ostream& c, MyString& m) ;
	friend ostream& operator<<(ostream& c, MyString* m) ;
	char& operator[](int k);
	char& operator()(int k);
	MyString operator+(MyString ms);
	bool operator==(MyString ms);
	bool compare(char *c1, char * c2);
	char* c_str();
	int find(char c);
	bool isEmpty();
};
ostream& operator<<(ostream& c, MyString& m) ;
ostream& operator<<(ostream& c, MyString* m) ;

#endif
