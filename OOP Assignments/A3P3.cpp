/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem3 毛哥的计算器 */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <stack>
using namespace std;

#pragma region 折叠区域_高精度算法_除法暂时为低精度

/// <summary>
/// 去除负号，并返回是否负数
/// </summary>
/// <param name="strNum">以字符串表示的数字</param>
/// <returns>是否为负数</returns>
bool removeMinus(string& strNum)
{
	if (strNum[0] == '-')
	{
		strNum = strNum.substr(1, strNum.length() - 1);
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// 高精度加法
/// </summary>
/// <param name="add1">加数1，非负</param>
/// <param name="add2">加数2，非负</param>
/// <returns>和，非负</returns>
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

/// <summary>
/// 高精度减法
/// </summary>
/// <param name="rdc1">被减数，非负</param>
/// <param name="rdc2">减数，非负</param>
/// <returns>差，带符号</returns>
string highPrecisionReduce(string rdc1, string rdc2)
{
	bool isNegative = false;
	/*字符串预处理*/
	if (rdc1.length() < rdc2.length() || (rdc1.length() == rdc2.length() && rdc1 < rdc2))	//交换两数,使大的在前
	{
		swap(rdc1, rdc2);
		isNegative = true;
	}
	int deltaLen = (int)(rdc1.length() - rdc2.length());
	for (int i = 0; i < deltaLen; i++)	//补0
	{
		rdc2 = "0" + rdc2;
	}
	/*进行减法运算*/
	string result;
	bool borrow = false;	//借位
	for (int i = (int)max(rdc1.length(), rdc2.length()) - 1; i >= 0; i--)
	{
		int a = rdc1[i] - '0';	//字符转为数字
		int b = rdc2[i] - '0';
		int delta = a - b - borrow;

		if (delta < 0)
		{
			borrow = true;
			delta += 10;
		}
		else
		{
			borrow = false;
		}

		result += (delta + '0');
	}
	/* 删除最高位的0 */
	while (result.length() != 1 && result[result.length() - 1] == '0')
	{
		result.pop_back();
	}
	reverse(result.begin(), result.end());	//反转字符串
	if (isNegative)
	{
		result = "-" + result;
	}
	return result;
}

/// <summary>
/// 高精度乘法
/// </summary>
/// <param name="mut1">乘数1，正负均可</param>
/// <param name="mut2">乘数2，正负均可</param>
/// <returns>积，带符号</returns>
string highPrecisionMutil(string mut1, string mut2)
{
	string result;
	bool isNegative1 = removeMinus(mut1);
	bool isNegative2 = removeMinus(mut2);
	/* 反向存储 */
	int len1 = (int)mut1.length();
	vector<int> num1(len1);
	for (int i = 0; i < len1; i++)
	{
		num1[i] = mut1[len1 - i - 1] - '0';
	}
	int len2 = (int)mut2.length();
	vector<int> num2(len2);
	for (int i = 0; i < len2; i++)
	{
		num2[i] = mut2[len2 - i - 1] - '0';
	}

	int carry = 0;	//进位
	vector<int> product(len1 + len2 + 1);
	for (int i = 0; i < len1; i++)
	{
		int carry = 0;
		for (int j = 0; j < len2; j++)
		{
			product[i + j] = product[i + j] + num1[i] * num2[j] + carry;
			carry = product[i + j] / 10;
			product[i + j] = product[i + j] % 10;
		}
		product[i + len2] = carry;         //进位
	}
	for (int i = 0; i < len1 + len2 + 1; i++)
	{
		result = result + (char)(product[i] + '0');
	}

	/* 删除最高位的0 */
	while (result.length() != 1 && result[result.length() - 1] == '0')
	{
		result.pop_back();
	}

	reverse(result.begin(), result.end());	//反转字符串
	if (isNegative1 != isNegative2)
	{
		result = '-' + result;
	}
	return result;
}
#pragma endregion

/// <summary>
/// 查找字符串中非数字的位置
/// </summary>
/// <param name="str">字符串</param>
/// <param name="startPos">查找起始位置</param>
/// <returns>非数字的位置，未找到返回-1</returns>
int findNonDigit(string str, int startPos = 0)
{
	for (int i = startPos; i < str.length(); i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// 分割字符串为数字＋运算符
/// </summary>
/// <param name="result">存放分割后的字符串，数字和运算符各占一个元素</param>
/// <param name="str">要分割的字符串</param>
void splitDigitAndOperator(vector<string>& result, string str)
{
	int startPos = 0;
	int endPos = findNonDigit(str);
	while (true)
	{
		/* 数字进栈 */
		if (endPos == -1)
		{
			result.push_back(str.substr(startPos, str.length() - startPos));
			break;
		}
		else
		{
			result.push_back(str.substr(startPos, endPos - startPos));
			result.push_back(str.substr(endPos, 1));
			startPos = endPos + 1;
			endPos = findNonDigit(str, startPos);
		}
	}
}

/// <summary>
/// 返回运算符的优先级
/// </summary>
/// <param name="ope">运算符</param>
/// <returns>优先级</returns>
int operatorLevel(char ope)
{
	if (ope == '*' || ope == '/' || ope == '%')
	{
		return 5;
	}
	else if (ope == '+' || ope == '-')
	{
		return 6;
	}
	return -1;
}

/// <summary>
/// 比较运算符的优先级
/// </summary>
/// <param name="ope1">运算符1</param>
/// <param name="ope2">运算符2</param>
/// <returns>优先级差值，运算符1优先级低返回正数</returns>
int operatorCompare(char ope1, char ope2)
{
	return operatorLevel(ope1) - operatorLevel(ope2);
}

/// <summary>
/// 计算表达式，仅支持+-*/
/// </summary>
/// <param name="ope">运算符</param>
/// <param name="num1">数字1</param>
/// <param name="num2">数字2</param>
/// <returns>返回是否计算成功</returns>
bool computer(char ope, string num1, string num2, string& result)
{
	if (ope == '*')
	{
		result = highPrecisionMutil(num1, num2);
		return true;
	}
	else if (ope == '/')
	{
		if (num2 == "0")
		{
			cout << "error";
			return false;
		}
		char temp[10];
		char* p = temp;

		result = to_string(strtoll(num1.c_str(), &p, 10) / strtoll(num2.c_str(), &p, 10));

		return true;
	}
	else if (ope == '+' || ope == '-')
	{
		if (ope == '+')
		{
			bool isNegative1 = removeMinus(num1);
			bool isNegative2 = removeMinus(num2);
			if (isNegative1 == true && isNegative2 == true)	//均负
			{
				result = highPrecisionAdd(num1, num2);
				result = "-" + result;
				return true;
			}
			if (isNegative1 == false && isNegative2 == true)	//第二个负，相当于减
			{
				result = highPrecisionReduce(num1, num2);
				return true;
			}
			if (isNegative1 == true && isNegative2 == false)	//第一个负，相当于第二个减第一个
			{
				result = highPrecisionReduce(num2, num1);
				return true;
			}
			if (isNegative1 == false && isNegative2 == false)	//均正
			{
				result = highPrecisionAdd(num1, num2);
				return true;
			}
		}
		if (ope == '-')
		{
			bool isNegative1 = removeMinus(num1);
			bool isNegative2 = removeMinus(num2);
			if (isNegative1 == true && isNegative2 == true)	//均负,相当于第二个减第一个
			{
				result = highPrecisionReduce(num2, num1);
				return true;
			}
			if (isNegative1 == false && isNegative2 == true)	//第二个负，相当于加
			{
				result = highPrecisionAdd(num1, num2);
				return true;
			}
			if (isNegative1 == true && isNegative2 == false)	//第一个负，相当于加，最后取反
			{
				result = highPrecisionAdd(num1, num2);
				result = "-" + result;
				return true;
			}
			if (isNegative1 == false && isNegative2 == false)	//均正
			{
				result = highPrecisionReduce(num1, num2);
				return true;
			}
		}
	}

	return false;

}

/// <summary>
/// 进行栈的一次计算
/// </summary>
/// <param name="operatorStack">运算符栈</param>
/// <param name="numStack">数字栈</param>
/// <returns></returns>
bool stackComputer(stack<char>& operatorStack, stack<string>& numStack)
{
	/* 优先级低或相等，栈顶运算符出栈1个，数字栈出栈2个，运算完的数字栈进栈1个 */
	char op = operatorStack.top();
	operatorStack.pop();
	string num1 = numStack.top();
	numStack.pop();
	string num2 = numStack.top();
	numStack.pop();
	string result;

	if (!computer(op, num2, num1, result))
	{
		return false;
	}
	numStack.push(result);

	return true;
}

int main()
{
	string input;
	cin >> input;

	vector<string> elements;
	splitDigitAndOperator(elements, input);	//分割字符串

	stack<string> numStack;		//数字栈
	stack<char> operatorStack;	//运算符栈

	char temp[10];
	char* p = temp;
	/* 先进栈 */
	numStack.push(elements[0]);
	operatorStack.push(elements[1][0]);
	numStack.push(elements[2]);

	/* 循环比较优先级进栈 */
	int pos = 3;	//运算符的位置为单数
	while (pos < elements.size())
	{
		if (operatorStack.size() == 0 || operatorCompare(operatorStack.top(), elements[pos][0]) > 0)
		{
			/* 优先级高，进栈 */
			operatorStack.push(elements[pos][0]);
			numStack.push(elements[pos + 1]);
			pos += 2;
		}
		else
		{
			if (!stackComputer(operatorStack, numStack))
			{
				return -1;
			}
		}
	}

	/* 输入流空，处理栈 */
	while (numStack.size() != 1)
	{
		if (!stackComputer(operatorStack, numStack))
		{
			return -1;
		}
	}
	string result;
	result = numStack.top();
	if (result.length() > 6)
	{
		bool isNegative = removeMinus(result);
		if (isNegative)
		{
			result = "-" + result.substr(result.length() - 6);
		}
		else
		{
			result = result.substr(result.length() - 6);
		}
	}
	cout << atoi(result.c_str()) % 10000 << endl;

	return 0;
}