#include <iostream>
#include <string>

using namespace std;

class NvGui{
private:
	string name;
	int age;
	string address;
public:
	NvGui();
	NvGui(string name, int age, string address);
	~NvGui();
	void setName(string name);
	void setAge(int age);
	void setAddress(string address);
	string getName();
	int getAge();
	string getAddress();
	NvGui& show();
};

void setParams(NvGui *nv, string name, int age, string address);
void printNvGui(NvGui *nv);
void setParams(NvGui &nv, string name, int age, string address);
void printNvGui(NvGui &nv);
void getObject(NvGui *p);
