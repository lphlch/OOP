/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
#include <vector>
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
/// 扔人
/// </summary>
/// <param name="people">人们，引用</param>
/// <param name="n">海盗和人质的数量（一半）</param>
/// <param name="k">报数间隔</param>
void throwPeople(vector<bool>& people, int n, int k)
{
	int pos = 1;	//报数位置
	for (int i = 0; i < n; i++)	//i代表被扔下去的人数量
	{
		for (int j = 1; j < k; j++)
		{
			if (people[pos] == false)	//如果这个倒霉蛋已经被扔下去了,则不计数
			{
				j--;
			}
			else if (pos == 2 * n)
			{
				pos = 0;
			}
			pos++;
		}

		/*如果这个人已经被扔，继续报数到没被扔的人，再退出循环*/
		while (true)
		{
			if (people[pos] == true)
			{
				people[pos] = false;	//扔人
				break;
			}
			if (pos == 2 * n)
			{
				pos = 0;
			}
			pos++;
		}
	}
}

int main()
{
	vector<bool> people;
	int n, k;

	/* 输入检测 */
	cerr << "输入n，k" << endl;
	if (!(inputWithCheck(n, 1, 999) && inputWithCheck(k, 2, 999)))	//函数范围闭区间，故为999
	{
		cerr << "毛哥意识到这实在太浪费时间了，就把他们全部扔掉了" << endl;
		return -1;
	}

	people.resize(2 * n + 1, true);
	throwPeople(people, n, k);

	for (int i = 1; i < people.size(); i++)
	{
		if (people[i] == true)
		{
			cout << "+";
		}
		else
		{
			cout << "@";
		}
	}

	return 0;
}
