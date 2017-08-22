#include <iostream>
#include <vector>
#include <string>

#include "File.h"

using namespace std;

int main()
{
	volatile int display_register;
	volatile Task* curr_task;
	volatile int iax[max_size];
	volatile Screen bitmapBuf;
	volatile int v;
	int *volatile vip;
	volatile int *ivp;
	volatile int *volatile vivp;
	
	int *ip = &v; 
	ivp = &v;
	vivp = &v;
}