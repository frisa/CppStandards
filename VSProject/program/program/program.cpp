#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>

using namespace std;

class A
{
private:
	int x;
	int y;

public:
	A() 
	{
		this->x = 1;
		this->y = 2;
	}
	A(const A&) = delete;
};



int main()
{
	int a = 20;
	auto ab = 20;
	decltype(ab) aab = ab;

	A ca;


	cout << "variable is " << aab << endl;

	cout << "C++ Standards" << endl;
	Sleep(3000);
	return 0;
}