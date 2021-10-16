/******************************************************
 !!!Please open by UTF-8 if random codes appeared!!!

 2052336 吕品灏

 请在Windows环境下，使用MSVC编译器以Realease x64运行
 Visual Studio Community 2019 ,版本16.9.4
 其他编译器(包括但不限于GCC(DevC++)、Clang)
 可能会出现警告、编译失败或其他问题

 Copyright © 2021 吕品灏, All rights reserved.
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#define SIZE 5
using namespace std;

struct Point
{
	int x = 0;
	int y = 0;
};

template <typename T>
struct Stack
{
	T elems[SIZE]{};
	// head是栈当前尾部的下标，通常我们称之为栈顶
	int head = 0;
	void push(T elem)
	{
		/* ⼊栈操作 */
		elems[head++] = elem;
	}
	T pop()
	{
		/* 出栈操作 */
		return elems[--head];
	}
	bool isEmpty()
	{
		/* 判断栈是否为空，思考⼀下什么时候需要调⽤该函数？ */
		return !head;
	}
	bool isFull()
	{
		/* 判断栈是否已满，思考⼀下什么时候需要调⽤该函数？ */
		if (head >= SIZE)
		{
			return true;
		}
		return false;
	}
	void print()
	{
		/* 打印当前栈内元素，格式如下（分别以T为string、Point时，以及栈为空举例）：
		[today,is,a,good,day,]
		[(1,2),(3,4),(7,8),]
		[]
		左边为栈底，右边为栈顶（即尾部）。为⽅便循环处理，栈顶元素后⾯的逗号⽆需去除
		*/
		cout << '[';
		for (int i = 0; i < head; i++)
		{
			cout << elems[i] << ',';
		}
		cout << ']' << endl;
	}
};
void Stack <Point>::print()
{
	cout << '[';
	for (int i = 0; i < head; i++)
	{
		cout << '(' << elems[i].x << ',' << elems[i].y << ')' << ',';
	}
	cout << ']' << endl;
}

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

/// <summary>
/// 控制栈
/// </summary>
/// <typeparam name="Type">模板类型</typeparam>
template<typename Type>
void stackControl()
{
	Stack <Type> stack;
	int type = 0;
	cin >> type;

	while (type != 0)
	{
		switch (type)
		{
			case 1:
				/* 入栈 */
			{
				Type input;
				cin >> input;
				if (!stack.isFull())
				{
					stack.push(input);
				}
				else
				{
					cout << "Stack is full!";
				}
			}
			break;
			case 2:
				/* 出栈 */
				if (!stack.isEmpty())
				{
					cout << stack.pop() << " is popped" << endl;
				}
				else
				{
					cout << "Stack is empty!";
				}
				break;
			default:
				break;
		}
		cin >> type;
	}

	stack.print();
}
template <> void stackControl<Point>()
{
	Stack <Point> stack;
	int type = 0;
	cin >> type;

	while (type != 0)
	{
		switch (type)
		{
			case 1:
				/* 入栈 */
			{
				string pointStr;
				vector<string> pointPResult;
				cin >> pointStr;
				splitString(pointPResult, pointStr, ',');
				Point pointIn;
				pointIn.x = atoi(pointPResult[0].c_str());
				pointIn.y = atoi(pointPResult[1].c_str());
				if (!stack.isFull())
				{
					stack.push(pointIn);
				}
				else
				{
					cout << "Stack is full!";
				}
			}
			break;
			case 2:
				/* 出栈 */
				if (!stack.isEmpty())
				{
					Point pointOut = stack.pop();
					cout << '(' << pointOut.x << ',' << pointOut.y << ')' << " is popped" << endl;
				}
				else
				{
					cout << "Stack is empty!";
				}
				break;
			default:
				break;
		}
		cin >> type;
	}

	stack.print();
}

int main()
{
	int type;
	cin >> type;
	/* 根据类型调用对应栈定义 */
	switch (type)
	{
		case 0:
			stackControl<int>();
			break;
		case 1:
			stackControl<string>();
			break;
		case 2:
			stackControl<Point>();
			break;
		default:
			cout << "程序似乎无法处理你输入的类型哎\n(っ °Д °;)っ" << endl;
			return EXIT_FAILURE;
			break;
	}
	return 0;
}