/* 2052336 吕品灏 */
/* Problem2 进制之谜 */
/* 请使用MSVC编译器(VS2019)，其他编译器(包括但不限于GCC(DevC++))可能会编译失败 */
#include <iostream>
#include <stdlib.h>
using namespace std;

/// <summary>
/// 输入并检测是否有误，闭区间
/// </summary>
/// <param name="input">输入，引用</param>
/// <param name="min">范围最小值</param>
/// <param name="max">范围最大值</param>
/// <returns>true无误，false有误</returns>
bool inputWithCheck(int& input, int min, int max)
{
	cin >> input;
	if (1 == cin.fail())	//检测是否出错
	{
		cin.clear();
		cin.ignore(5000, '\n');
		return false;
	}
	else if (input >= min && input <= max)
	{
		return true;
	}
	return false;
}

int main()
{
	int m, k;
	char kStr[10] = { 0 };
	char* p;

	if (!inputWithCheck(m, 2, 20))	//m输入错误
	{
		return -1;
	}
	cin >> k;
	_itoa_s(k, kStr, 10);	//将k转换为字符串
	long int n = strtol(kStr, &p, 6);	//将k转为十进制

	if ((*p) != 0)	//k不是6进制，输入错误
	{
		return -1;
	}

	char out[17] = { 0 };
	_itoa_s(n, out, m);	//将n转为对应进制
	_strupr_s(out);		//转为大写
	cout << out;

	return 0;
}
