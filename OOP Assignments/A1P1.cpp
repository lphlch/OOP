/* 2052336 吕品灏 */
/* Problem1 三角封印 */
/* 请使用MSVC编译器(VS2019)，其他编译器(包括但不限于GCC(DevC++))可能会编译失败 */
#include <iostream>
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

int main()
{
	int a, b, c;

	if (inputWithCheck(a, 1, 9999) &&
		inputWithCheck(b, 1, 9999) &&
		inputWithCheck(c, 1, 9999))		//检测输入，因为检测函数为闭区间，故为1-9999
	{
		/*输入正确*/
		int side[3] = { a,b,c };
		sort(side, side + 3);	//从小到大排序
		if (side[0] + side[1] > side[2])	//最小的两边之和大于第三边即可认为是三角形
		{
			cout << "封印解除";
		}
		else
		{
			cout << "解除失败";
		}
	}
	else
	{
		/*输入错误*/
		return -1;
	}

	return 0;
}
