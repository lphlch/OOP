/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem2 ��ʿ�Ĺ��� */
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
using namespace std;

int main()
{
	int k;
	long long coins = 0;
	cerr << "������k" << endl;
	cin >> k;

	/* �쳣���봦�� */
	if (k > 36500)
	{
		cerr << "ë����Ϊ��ʿ������ܻ���ô�õĻ�������Ҫɶ����أ����Ǿ���������" << endl;
		return -1;
	}
	if (k < 0)
	{
		cerr << "��ʿͻȻ��ʶ����ǰ���첻��û�й��ʣ���Ȼ��������Ǯ��һŭ֮�°�ë���ɱ��" << endl;
		return -1;
	}

	/*ѭ����ÿ��һ��k--��k=0�������ʷ����ˣ���������ѭ��*/
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
