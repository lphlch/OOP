/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem1 ë��ѧ����*/
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// ͳ���ַ������ַ����ֵĸ���
/// </summary>
/// <param name="num">Ҫͳ�Ƶ��ַ���</param>
/// <param name="value">�ַ�</param>
/// <returns>�ַ����ֵĴ���</returns>
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

	/* ������� */
	if (left > right)
	{
		cout << "Math Error" << endl;
		return -1;
	}

	/* ͳ������ */
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		count += includeCount(to_string(i), '2');
		cout<<i<<endl; 
	}

	cout << count;

	return 0;
}
