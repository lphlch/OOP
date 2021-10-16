/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem1 ��������*/
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */
/* ��֪��Ч�����⣺����������������������Խ��ǧ�꣩��������Ҫ�ϳ�ʱ����ܼ������� */
#include <iostream>
#include<algorithm>
using namespace std;

/// <summary>
/// ������ݼ��£�������µ��������
/// </summary>
/// <param name="year">��</param>
/// <param name="month">��</param>
/// <returns>�������,���󷵻�0</returns>
int dayNum(const int year, const int month)
{
	int flag = ((0 == year % 4) && (0 != year % 100)) || (0 == year % 400);	//�����ʶ
	switch (month) //�ж��·ݺ������Ƿ��Ӧ
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
/// �ж������Ƿ�Ϸ�
/// </summary>
/// <param name="date">Ҫ�жϵ�����,string</param>
/// <returns>T/F</returns>
bool isDate(string date)
{
	char temp[8];
	char* p = temp;
	int year = strtol(date.substr(0, 4).c_str(), &p, 10);
	int month = strtol(date.substr(4, 2).c_str(), &p, 10);
	int day = strtol(date.substr(6, 2).c_str(), &p, 10);
	if (month == 0 || month > 12)	//�·Ƿ�
	{
		return false;
	}
	if (day == 0 || day > dayNum(year, month))	//�շǷ�
	{
		return false;
	}
	return true;
}

/// <summary>
/// �������ж�
/// </summary>
/// <param name="num">Ҫ�жϵ�string</param>
/// <returns>T/F</returns>
bool isPalindrome(const string num)
{
	string revNum = num;
	reverse(revNum.begin(), revNum.end());
	/* ��ת */
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
	cerr << "����������" << endl;
	cin >> startDate >> endDate;
	int count = 0;

	/* ѭ��ÿһ�� */
	for (string date = startDate; date <= endDate; )
	{
		/* ���ںϷ����ж�+�������ж� */
		if (isDate(date) && isPalindrome(date))
		{
			count++;
			date[3]+=1;			//��Ч�ʵĸ��� 
			date[4]='0';
			date[5]='1';
			date[6]='0';
			date[7]='0';
		}
		date[7] = date[7] + 1;
		/* ���ڽ�һ�� */
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
