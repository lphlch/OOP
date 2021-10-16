/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem1 回文日期*/
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */
/* 已知的效率问题：对于区间过大的情况（比如跨越几千年），可能需要较长时间才能计算出结果 */
#include <iostream>
#include<algorithm>
using namespace std;

/// <summary>
/// 输入年份及月，输出该月的最大天数
/// </summary>
/// <param name="year">年</param>
/// <param name="month">月</param>
/// <returns>最大天数,错误返回0</returns>
int dayNum(const int year, const int month)
{
	int flag = ((0 == year % 4) && (0 != year % 100)) || (0 == year % 400);	//闰年标识
	switch (month) //判断月份和日期是否对应
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28 + flag;
		default:
			return 0;
	}
}

/// <summary>
/// 判断日期是否合法
/// </summary>
/// <param name="date">要判断的日期,string</param>
/// <returns>T/F</returns>
bool isDate(string date)
{
	char temp[8];
	char* p = temp;
	int year = strtol(date.substr(0, 4).c_str(), &p, 10);
	int month = strtol(date.substr(4, 2).c_str(), &p, 10);
	int day = strtol(date.substr(6, 2).c_str(), &p, 10);
	if (month == 0 || month > 12)	//月非法
	{
		return false;
	}
	if (day == 0 || day > dayNum(year, month))	//日非法
	{
		return false;
	}
	return true;
}

/// <summary>
/// 回文数判断
/// </summary>
/// <param name="num">要判断的string</param>
/// <returns>T/F</returns>
bool isPalindrome(const string num)
{
	string revNum = num;
	reverse(revNum.begin(), revNum.end());
	/* 反转 */
	if (revNum == num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string startDate;
	string endDate;
	cerr << "请输入日期" << endl;
	cin >> startDate >> endDate;
	int count = 0;

	/* 循环每一天 */
	for (string date = startDate; date <= endDate; )
	{
		/* 日期合法性判断+回文数判断 */
		if (isDate(date) && isPalindrome(date))
		{
			count++;
			date[3]+=1;			//对效率的改善 
			date[4]='0';
			date[5]='1';
			date[6]='0';
			date[7]='0';
		}
		date[7] = date[7] + 1;
		/* 日期进一天 */
		for (int i = 7; i > 0; i--)
		{
			if (date[i] > '9')
			{
				date[i] = date[i] - 10;
				date[i - 1] = date[i - 1] + 1;
			}
		}
	}

	cout << count << endl;

	return 0;
}
