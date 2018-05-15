#include <stdio.h>
#include <iostream>
#include <string>

#include <Windows.h>

#include <sstream>

using namespace std;



int main(int argc, char* argv[])
{
	//time_t now = time(0);

	//
	//cout << time(&now)<< endl;

	//time_t rawtime;
	//struct tm * timeinfo;

	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	//printf("Current local time and date: %s", asctime(timeinfo));


	SYSTEMTIME time;
	GetLocalTime(&time);
//	cout << time.wDay<<"   "<<time.wMonth<<"   "<<time.wYear << endl;
//	cout << time.wHour << "   " << time.wMinute << "   " << time.wSecond << endl;


	string cDate ;
	ostringstream convert;

	convert << time.wDay << "." << time.wMonth << "." << time.wYear;
	cDate = convert.str() + "_log.txt";
	cout << cDate << endl;


	return 0;
}