/* 2052336 ��Ʒ� */
/* Problem2 ����֮�� */
/* ��ʹ��MSVC������(VS2019)������������(������������GCC(DevC++))���ܻ����ʧ�� */
#include <iostream>
#include <stdlib.h>
using namespace std;

/// <summary>
/// ���벢����Ƿ����󣬱�����
/// </summary>
/// <param name="input">���룬����</param>
/// <param name="min">��Χ��Сֵ</param>
/// <param name="max">��Χ���ֵ</param>
/// <returns>true����false����</returns>
bool inputWithCheck(int& input, int min, int max)
{
	cin >> input;
	if (1 == cin.fail())	//����Ƿ����
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

	if (!inputWithCheck(m, 2, 20))	//m�������
	{
		return -1;
	}
	cin >> k;
	_itoa_s(k, kStr, 10);	//��kת��Ϊ�ַ���
	long int n = strtol(kStr, &p, 6);	//��kתΪʮ����

	if ((*p) != 0)	//k����6���ƣ��������
	{
		return -1;
	}

	char out[17] = { 0 };
	_itoa_s(n, out, m);	//��nתΪ��Ӧ����
	_strupr_s(out);		//תΪ��д
	cout << out;

	return 0;
}
