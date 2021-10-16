/* 2052336 ��Ʒ� */
/* Problem1 ���Ƿ�ӡ */
/* ��ʹ��MSVC������(VS2019)������������(������������GCC(DevC++))���ܻ����ʧ�� */
#include <iostream>
#include <algorithm>
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
	int a, b, c;

	if (inputWithCheck(a, 1, 9999) &&
		inputWithCheck(b, 1, 9999) &&
		inputWithCheck(c, 1, 9999))		//������룬��Ϊ��⺯��Ϊ�����䣬��Ϊ1-9999
	{
		/*������ȷ*/
		int side[3] = { a,b,c };
		sort(side, side + 3);	//��С��������
		if (side[0] + side[1] > side[2])	//��С������֮�ʹ��ڵ����߼�����Ϊ��������
		{
			cout << "��ӡ���";
		}
		else
		{
			cout << "���ʧ��";
		}
	}
	else
	{
		/*�������*/
		return -1;
	}

	return 0;
}
