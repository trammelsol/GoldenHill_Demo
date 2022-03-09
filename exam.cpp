#include <unistd.h>
#include<windows.h>
#include<iostream>
using namespace std;

int number = 1;

unsigned long __stdcall ThreadProc1(void* lp) {
	while (number < 100) {
		cout << "thread 1 :"<<number << endl;
		++number;
		Sleep(50);
	}

	return 0;
}

unsigned long __stdcall ThreadProc2(void* lp) {
	while (number < 100) {
		cout << "thread 2 :"<<number << endl;
		++number;
		Sleep(50);
	}

	return 0;
}

int main() {
	CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

	//Sleep(10*1000);

	cin.get();
    return 0;
}