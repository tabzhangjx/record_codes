// degrees.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

int main(int argc, char* argv[])
{   using namespace std;
    float degrees, minutes, seconds;
	cin>>degrees;
	cin>>minutes;
	cin>>seconds;

	float f = degrees + minutes/60 +seconds/3600;
	cout<<degrees<<" degrees, "<<minutes<<" minutes, "<<seconds<<" seconds = "<<f<<" degrees"<<endl;
    
	return 0;
}
