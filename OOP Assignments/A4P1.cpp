/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 吕品灏 */
/* Problem1 求中点 */
/* 请使用MSVC编译器(VS2019)以Realease x64运行，其他编译器(包括但不限于GCC(DevC++)、Clang)可能会编译失败或出现其他问题 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

#pragma region 折叠区域_求中点
/// <summary>
/// 求中点 主模板
/// </summary>
/// <typeparam name="T">可变类型</typeparam>
/// <param name="t1">可变类型1</param>
/// <param name="t2">可变类型2</param>
/// <returns>中点</returns>
template<typename T>
T middle(T t1, T t2)
{
	return (t1 + t2) / 2;
}
/// <summary>
/// 求中点 string具体化
/// </summary>
/// <param name="str1"></param>
/// <param name="str2"></param>
/// <returns></returns>
template<>string middle(string str1, string str2)
{
	string merge;
	if (str1.length() < str2.length())	//使长度大的在前面
	{
		swap(str1, str2);
	}
	string result(str1);
	for (int i = 1; i <= str2.length(); i++)
	{
		result[str1.length() - i] = middle(str1[str1.length() - i], str2[str2.length() - i]);
	}
	return result;
}
/// <summary>
/// 求中点 Point结构体具体化
/// </summary>
/// <param name="p1"></param>
/// <param name="p2"></param>
/// <returns></returns>
template<>Point middle(Point p1, Point p2)
{
	Point result;
	result.x = middle(p1.x, p2.x);
	result.y = middle(p1.y, p2.y);
	return result;
}
/// <summary>
/// 求中点 Point*结构体指针具体化
/// </summary>
/// <param name="p1"></param>
/// <param name="p2"></param>
/// <returns></returns>
template<>Point* middle(Point* p1, Point* p2)
{
	static Point result;
	result.x = middle(p1->x, p2->x);
	result.y = middle(p1->y, p2->y);
	return &result;
}
#pragma endregion

/// <summary>
/// 分割字符串
/// </summary>
/// <param name="result">分割后的字符串动态数组</param>
/// <param name="str">要分割的字符串</param>
/// <param name="delim">分隔符</param>
void splitString(vector<string>& result, string str, char delim)
{
	result.clear();
	for (int i = 0; i < str.length(); i++)
	{
		int pos = (int)str.find(delim, i);
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
			if (subStr[0] != delim)
			{
				result.push_back(subStr);
			}
			break;
		}
	}
}

int main()
{
	/*int*/
	int int1, int2;
	cin >> int1 >> int2;
	cout << middle(int1, int2) << endl;
	/*double*/
	double dob1, dob2;
	cin >> dob1 >> dob2;
	cout << middle(dob1, dob2) << endl;
	/*char*/
	char chr1, chr2;
	cin >> chr1 >> chr2;
	cout << middle(chr1, chr2) << endl;
	/*string*/
	string str1, str2;
	cin >> str1 >> str2;
	cout << middle(str1, str2) << endl;
	/*Point*/
	string point1str, point2str;
	vector<string>pointResult;
	Point point1, point2;
	cin >> point1str >> point2str;
	splitString(pointResult, point1str, ',');
	point1.x = atoi(pointResult[0].c_str());
	point1.y = atoi(pointResult[1].c_str());
	splitString(pointResult, point2str, ',');
	point2.x = atoi(pointResult[0].c_str());
	point2.y = atoi(pointResult[1].c_str());
	cout << '(' << middle(point1, point2).x << ',' << middle(point1, point2).y << ')' << endl;
	/*Point* */
	string pointP1str, pointP2str;
	vector<string>pointPResult;
	cin >> pointP1str >> pointP2str;
	splitString(pointPResult, pointP1str, ',');
	point1.x = atoi(pointPResult[0].c_str());
	point1.y = atoi(pointPResult[1].c_str());
	splitString(pointPResult, pointP2str, ',');
	point2.x = atoi(pointPResult[0].c_str());
	point2.y = atoi(pointPResult[1].c_str());
	cout << '(' << middle(&point1, &point2)->x << ',' << middle(&point1, &point2)->y << ')' << endl;

	return 0;
}