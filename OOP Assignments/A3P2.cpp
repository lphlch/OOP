/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem2 毛哥的论文 */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

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
/// 分割字符串
/// </summary>
/// <param name="result">分割后的字符串动态数组</param>
/// <param name="str">要分割的字符串</param>
/// <param name="delim">分隔符</param>
void splitString(vector<string>& result, string str, char delim)
{
	for (int i = 0; i < str.length(); i++)
	{
		int pos = (int)str.find(' ', i);
		if (pos != -1)
		{
			//赋单词
			string subStr = str.substr(i, pos - i);
			if (subStr != "")	//不赋空格
			{
				result.push_back(subStr);
			}
			i = pos;
		}
		else
		{
			//赋最后
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
	transform(input.begin(), input.end(), input.begin(), ::tolower);	//转为小写

	vector<string> words;
	splitString(words, input, ' ');	//分割字符串

	/* 数据的查找 */
	vector<Dictionary> dictionarys;
	for (string word : words)
	{
		bool isFind = false;
		for (Dictionary& dictionary : dictionarys)
		{
			/* 查找数据 */
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

	/* 输出 */
	for (Dictionary dictionary : dictionarys)
	{
		cout << dictionary.key << ' ' << dictionary.value << endl;
	}

	return 0;
}