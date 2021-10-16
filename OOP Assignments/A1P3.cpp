/* 2052336 吕品灏 */
/* Problem3 A+B之谜 */
/* 请使用MSVC编译器(VS2019)，其他编译器(包括但不限于GCC(DevC++))可能会编译失败 */
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
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

/// <summary>
/// 高精度加法
/// </summary>
/// <param name="add1">加数1</param>
/// <param name="add2">加数2</param>
/// <returns>string和</returns>
string highPrecisionAdd(string add1, string add2)
{
	/*字符串预处理*/
	if (add1.length() > add2.length())	//交换两数,使小的在前
	{
		swap(add1, add2);
	}
	int deltaLen = (int)(add2.length() - add1.length());
	for (int i = 0; i < deltaLen; i++)	//补0
	{
		add1 = "0" + add1;
	}
	/*进行加法运算*/
	string result;
	bool carry = false;	//进位
	for (int i = (int)max(add1.length(), add2.length()) - 1; i >= 0; i--)
	{
		int a = add1[i] - '0';	//字符转为数字
		int b = add2[i] - '0';
		int sum = a + b + carry;

		if (sum >= 10)
		{
			carry = true;
			sum -= 10;
		}
		else
		{
			carry = false;
		}

		result += (sum + '0');
	}
	if (carry == true)	//最高位的进位
	{
		result += "1";
	}
	reverse(result.begin(), result.end());	//反转字符串
	return result;
}

int main()
{
	int m, n;
	string a, b;
	if (!inputWithCheck(m, 1, 100))			//输入错误
	{
		return -1;
	}
	cin >> a;
	if (!inputWithCheck(n, 1, 100))			//输入错误
	{
		return -1;
	}
	cin >> b;

	cout << highPrecisionAdd(a, b);			//进行高精度加法

	return 0;
}