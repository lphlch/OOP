/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem2 函数指针 */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
#include <windows.h>
using namespace std;

int add(int a, int b)
{
	return a + b;
}
int subtract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}

int calc(int a, int b, int(*p_func)(int, int))
{
	return p_func(a, b);
}

int main()
{
	string str;	//运算符
	int switchOn;
	int a, b;
	cin >> str >> a >> b;

	if (str == "add")	//似乎无法直接switch-case string类型？故出此下策
	{
		switchOn = 1;
	}
	else if (str == "subtract")
	{
		switchOn = 2;
	}
	else if (str == "multiply")
	{
		switchOn = 3;
	}
	else if (str == "divide")
	{
		switchOn = 4;
	}
	else
	{
		MessageBoxA(GetForegroundWindow(), "由于你输入了错误的运算符，程序崩溃啦(～￣▽￣)～\n请问你知道点击按钮后会关闭程序吗？", "好耶，程序崩溃啦", 4);
		return EXIT_FAILURE;
	}

	switch (switchOn)
	{
		case 1:
			cout << calc(a, b, add) << endl;
			break;
		case 2:
			cout << calc(a, b, subtract) << endl;
			break;
		case 3:
			cout << calc(a, b, multiply) << endl;
			break;
		case 4:
			cout << calc(a, b, divide) << endl;
			break;
		default:
			return EXIT_FAILURE;
	}

	return 0;
}

/*
函数指针传参：通过一个调用函数的函数来传递需要真正被调用的函数；
优点：对不同函数的具体调用在函数内部，修改时只需要修改传参时候传入的函数名，多次调用时只需修改一次；
	  具体的实现和调用分离，利于模块化编程；
缺点：函数调用的具体作用不明显，缺乏直观性;
	  被调用的函数必须返回类型和参数类型相同，无法针对不同参数类型做重载；

直接调用不同函数：直接根据不同的条件调用函数；
优点：可以进行重载，适配不同参数类型；
缺点：对不同函数的具体调用在函数外部，修改时可能需要重复修改；
*/