/*
 * Thread.cpp
 *
 *  Created on: 2019年3月15日
 *      Author: Administrator
 */

#include "Thread.h"
#include <iostream>
#include <thread>
using namespace std;

Thread::Thread() {
	// TODO Auto-generated constructor stub

}

Thread::~Thread() {
	// TODO Auto-generated destructor stub
}

void printInThread(int i){
	cout << i << endl;
	this_thread::sleep_for(chrono::seconds(random()%5));
	cout << i << endl;
}

void testThread1(){
	for(int i = 0; i < 10; i++){
		thread *t = new thread(printInThread, i);
		t->detach();
		//thread t(printInThread, i);
		//t.join();
		delete t;
	}
	this_thread::sleep_for(chrono::seconds(9));
}

