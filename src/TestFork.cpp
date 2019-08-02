#include "TestFork.h"
#include "unistd.h"
#include "stdio.h"
void TestFork::test1(){
	pid_t p = fork();
	printf("pid=%d\n", p);
}
