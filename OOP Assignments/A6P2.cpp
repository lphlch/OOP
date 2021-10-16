/************************************************************************************************
 !!!Please open by UTF-8 with BOM (code page 65001) if random codes appeared or error occurred!!!

 2052336 吕品灏 Problem 2

 请在Windows环境下，使用MSVC编译器以Realease x64运行
 Visual Studio Community 2019 ,版本16.9.3
 其他编译器(包括但不限于GCC(DevC++)、Clang)
 可能会出现警告、编译失败或其他问题

 Copyright © 2021 吕品灏, All rights reserved.
************************************************************************************************/

#define SIZE 5
#include <iostream>
using namespace std;

#pragma region Point的定义及其输入输出重载
struct Point
{
	int x = 0;
	int y = 0;
};
/// <summary>
/// 针对Point的>>运算符重载
/// </summary>
/// <param name="is">输入流</param>
/// <param name="point">Point类型</param>
/// <returns>输入流</returns>
istream& operator>>(istream& is, Point& point)
{
	char ch;
	is >> point.x >> ch >> point.y;
	return is;
}
/// <summary>
/// 针对Point的<<运算符重载
/// </summary>
/// <param name="os">输出流</param>
/// <param name="point">Point类型</param>
/// <returns>输出流</returns>
ostream& operator<<(ostream& os, Point point)
{
	os << '(' << point.x << ',' << point.y << ')';
	return os;
}
#pragma endregion
#pragma region Stack的定义
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
#pragma endregion

template<typename T>
struct Queue
{
	// 现在我们没有elems数组了，只有stackA和stackB两个栈变量，需要你通过在inQueue和deQueue函数中使⽤这俩栈变量的pop和push函数来模拟队列。
	Stack<T> stackA;	//A为主队列
	Stack<T> stackB;	//B为出栈辅助队列
	void inQueue(T elem)
	{
		stackA.push(elem);
		return;
	}
	T deQueue()
	{
		while (!stackA.isEmpty())
		{
			stackB.push(stackA.pop());
		}
		T popElem = stackB.pop();
		while (!stackB.isEmpty())
		{
			stackA.push(stackB.pop());
		}
		return popElem;
	}
	bool isEmpty()
	{
		return stackA.isEmpty();
	}
	bool isFull()
	{
		return stackA.isFull();
	}
	void print()
	{
		stackA.print();
		return;
	}
};

/// <summary>
/// 队列操控
/// </summary>
/// <typeparam name="Type">可变类型</typeparam>
template<typename Type>
void queueControl()
{
	Queue<Type> queue;
	int type = 0;
	cin >> type;

	while (type != 0)
	{
		switch (type)
		{
			case 1:
				/* 入 */
			{
				Type input;
				cin >> input;
				if (!queue.isFull())
				{
					queue.inQueue(input);
				}
				else
				{
					cout << "Queue is full!";
				}
			}
			break;
			case 2:
				/* 出 */
				if (!queue.isEmpty())
				{
					cout << queue.deQueue() << " is popped" << endl;
				}
				else
				{
					cout << "Queue is empty!";
				}
				break;
			default:
				break;
		}
		cin >> type;
	}
	queue.print();

	return;
}

int main()
{
	int type;
	cin >> type;
	switch (type)
	{
		case 0:
			queueControl<int>();
			break;
		case 1:
			queueControl<string>();
			break;
		case 2:
			queueControl<Point>();
			break;
		default:
			cout << "程序似乎无法处理你输入的类型哎\n(っ °Д °;)っ" << endl;
			return EXIT_FAILURE;
			break;
	}
	return 0;
}