/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem2 ë������� */
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Dictionary
{
	string key;
	int value = 0;
};

/// <summary>
/// �ָ��ַ���
/// </summary>
/// <param name="result">�ָ����ַ�����̬����</param>
/// <param name="str">Ҫ�ָ���ַ���</param>
/// <param name="delim">�ָ���</param>
void splitString(vector<string>& result, string str, char delim)
{
	for (int i = 0; i < str.length(); i++)
	{
		int pos = (int)str.find(' ', i);
		if (pos != -1)
		{
			//������
			string subStr = str.substr(i, pos - i);
			if (subStr != "")	//�����ո�
			{
				result.push_back(subStr);
			}
			i = pos;
		}
		else
		{
			//�����
			string subStr = str.substr(i, str.length() - 1);
			if (subStr != " ")
			{
				result.push_back(subStr);
			}
			break;
		}
	}
}

int main()
{
	string input;
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);	//תΪСд

	vector<string> words;
	splitString(words, input, ' ');	//�ָ��ַ���

	/* ���ݵĲ��� */
	vector<Dictionary> dictionarys;
	for (string word : words)
	{
		bool isFind = false;
		for (Dictionary& dictionary : dictionarys)
		{
			/* �������� */
			if (dictionary.key == word)
			{
				dictionary.value++;
				isFind = true;
				break;
			}
		}
		if (!isFind)
		{
			Dictionary dic;
			dic.key = word;
			dic.value++;
			dictionarys.push_back(dic);
		}
	}

	/* ��� */
	for (Dictionary dictionary : dictionarys)
	{
		cout << dictionary.key << ' ' << dictionary.value << endl;
	}

	return 0;
}