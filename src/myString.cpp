#include <iostream>
#include "myString.h"
using namespace std;

int MyString::getLength(const char *p){
	int count = 0;
	if(NULL != p){
		while(*p != '\0'){
			count++;
			p++;
		}
	}
	return count;
}
MyString::MyString(){
	str = new char(1);
	*str = '\0';
	length = 0;
	//cout<<"MyString()"<<endl;
}
MyString::MyString(const char *p){
	if(NULL != p){
		length = getLength(p);
		str = new char(length + 1);
		for(int i = 0; i < length; i++){
			str[i] = p[i];
		}
		str[length] = '\0';
		//cout<<"MyString(const char *p)"<<endl;
	}
};
MyString::MyString(int l){
	if(l < 0){
		l = 0;
	}
	length = l;
	str = new char[l + 1];
	str[l] = '\0';
};
MyString::~MyString(){
}
int MyString::size(){
	return this->length;
};
void MyString::print(){
	cout<<str<<endl;
}
char& MyString::operator[](int k){
	int index = 0;
	if(k >= length){
		index = length - 1;
	}else{
		index = k;
	}
	return *(str + index);
};
char& MyString::operator()(int k){
	int index = 0;
	if(k >= length){
		index = length - 1;
	}else{
		index = k;
	}
	return *(str + index);
};
MyString MyString::operator+(MyString ms){
	int s_length = this->length + ms.length;
	MyString s(s_length + 1);
	int i = 0;
	for(; i < this->length; i++){
		s[i] = str[i];
	}
	for(int j = 0; j < ms.length; j++){
		s[i + j] = ms[j];
	}
	s[s_length] = '\0';
	return s;
};
bool MyString::operator==(MyString ms){
	if(this->length == ms.length){
		return compare(this->str, ms.str);
	}else{
		return false;
	}
};
bool MyString::compare(char *c1, char * c2){
	int i = 0;
	while(c1[i] != '\0' && c2[i] != '\0'){
		if(c1[i] != c2[i]){
			return false;
		}else{

		}
		i++;
	}
	return true;
};
char* MyString::c_str(){
	return str;
};
int MyString::find(char c){
	int i = 0;
	for(; i < length; i++){
		if(c == str[i]){
			return i;
		}
	}
	return -1;
};
bool MyString::isEmpty(){
	bool b = true;
	for(int i = 0; i < length; i++){
		if(str[i] != '\0'){
			b = false;
		}
	}
	return b;
}

ostream& operator<<(ostream& c, MyString& m){
	c<<m.str;
	return c;
} ;
ostream& operator<<(ostream& c, MyString* m){
	c<<m->str;
	return c;
} ;
