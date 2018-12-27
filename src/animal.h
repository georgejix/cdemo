#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
	string name;
	int age;
protected:
	void setName(string name);
	void setAge(int age);
	string getName();
	int getAge();
public:
	void show();
};

class Bird : public Animal{
private:
	int weight;
public:
	Bird(string name, int age);
	void setWeight(int weight);
	int getWeight();
};
