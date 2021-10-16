/* 2052336 ��Ʒ� */
/* Problem3 A+B֮�� */
/* ��ʹ��MSVC������(VS2019)������������(������������GCC(DevC++))���ܻ����ʧ�� */
#include <iostream>
#include <cstring>
#include <string>
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

/// <summary>
/// �߾��ȼӷ�
/// </summary>
/// <param name="add1">����1</param>
/// <param name="add2">����2</param>
/// <returns>string��</returns>
string highPrecisionAdd(string add1, string add2)
{
	/*�ַ���Ԥ����*/
	if (add1.length() > add2.length())	//��������,ʹС����ǰ
	{
		swap(add1, add2);
	}
	int deltaLen = (int)(add2.length() - add1.length());
	for (int i = 0; i < deltaLen; i++)	//��0
	{
		add1 = "0" + add1;
	}
	/*���мӷ�����*/
	string result;
	bool carry = false;	//��λ
	for (int i = (int)max(add1.length(), add2.length()) - 1; i >= 0; i--)
	{
		int a = add1[i] - '0';	//�ַ�תΪ����
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
	if (carry == true)	//���λ�Ľ�λ
	{
		result += "1";
	}
	reverse(result.begin(), result.end());	//��ת�ַ���
	return result;
}

int main()
{
	int m, n;
	string a, b;
	if (!inputWithCheck(m, 1, 100))			//�������
	{
		return -1;
	}
	cin >> a;
	if (!inputWithCheck(n, 1, 100))			//�������
	{
		return -1;
	}
	cin >> b;

	cout << highPrecisionAdd(a, b);			//���и߾��ȼӷ�

	return 0;
}