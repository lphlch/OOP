/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem2 骑士的工资 */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
using namespace std;

int main()
{
	int k;
	long long coins = 0;
	cerr << "请输入k" << endl;
	cin >> k;

	/* 异常输入处理 */
	if (k > 36500)
	{
		cerr << "毛哥认为骑士活如果能活这么久的话，还需要啥金币呢，于是决定不发了" << endl;
		return -1;
	}
	if (k < 0)
	{
		cerr << "骑士突然意识到他前几天不但没有工资，居然还倒贴了钱，一怒之下把毛哥刺杀了" << endl;
		return -1;
	}

	/*循环，每过一天k--，k=0表明工资发完了，跳出两层循环*/
	for (int coinPerDay = 1; k != 0; coinPerDay++)
	{
		for (int day = 1; day <= coinPerDay && k != 0; day++, k--)
		{
			coins += coinPerDay;
		}
	}

	cout << coins << endl;

	return 0;
}
