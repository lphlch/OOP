/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem1 毛哥学数数*/
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// 统计字符串中字符出现的个数
/// </summary>
/// <param name="num">要统计的字符串</param>
/// <param name="value">字符</param>
/// <returns>字符出现的次数</returns>
int includeCount(string str, char key)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == key)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int left, right;
	cin >> left >> right;

	/* 区间错误 */
	if (left > right)
	{
		cout << "Math Error" << endl;
		return -1;
	}

	/* 统计数据 */
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		count += includeCount(to_string(i), '2');
		cout<<i<<endl; 
	}

	cout << count;

	return 0;
}
