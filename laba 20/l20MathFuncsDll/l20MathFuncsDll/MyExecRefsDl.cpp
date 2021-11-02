#include <iostream>
#include"MathFuncsDll.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	double r;
	cout << "¬ведите радиус \nr=";
	cin >> r;
	cout << "P=" <<
		MathFuncs::MyMathFuncs::Perimetr(r) << endl;
	cout << "S=" <<
		MathFuncs::MyMathFuncs::Subtract(r) << endl;
	return 0;
}