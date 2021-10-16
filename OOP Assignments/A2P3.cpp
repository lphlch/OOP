/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem */
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
#include <vector>
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
/// ����
/// </summary>
/// <param name="people">���ǣ�����</param>
/// <param name="n">���������ʵ�������һ�룩</param>
/// <param name="k">�������</param>
void throwPeople(vector<bool>& people, int n, int k)
{
	int pos = 1;	//����λ��
	for (int i = 0; i < n; i++)	//i��������ȥ��������
	{
		for (int j = 1; j < k; j++)
		{
			if (people[pos] == false)	//��������ù���Ѿ�������ȥ��,�򲻼���
			{
				j--;
			}
			else if (pos == 2 * n)
			{
				pos = 0;
			}
			pos++;
		}

		/*���������Ѿ����ӣ�����������û���ӵ��ˣ����˳�ѭ��*/
		while (true)
		{
			if (people[pos] == true)
			{
				people[pos] = false;	//����
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

	/* ������ */
	cerr << "����n��k" << endl;
	if (!(inputWithCheck(n, 1, 999) && inputWithCheck(k, 2, 999)))	//������Χ�����䣬��Ϊ999
	{
		cerr << "ë����ʶ����ʵ��̫�˷�ʱ���ˣ��Ͱ�����ȫ���ӵ���" << endl;
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
