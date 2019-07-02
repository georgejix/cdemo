#include "TestPrint.h"
#include <stdio.h>
void TestPrint::printByteArray(){
	char bytes[] = {0x15, 0x16, 0x17, 0x18, 0x19};
	printf("%x", bytes[0]);
}
