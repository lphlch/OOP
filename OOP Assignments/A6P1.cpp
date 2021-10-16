/******************************************************
 !!!Please open by UTF-8 if random codes appeared!!!

 2052336 吕品灏 Problem 1

 请在Windows环境下，使用MSVC编译器以Realease x64运行
 Visual Studio Community 2019 ,版本16.9.3
 其他编译器(包括但不限于GCC(DevC++)、Clang)
 可能会出现警告、编译失败或其他问题

 Copyright © 2021 吕品灏, All rights reserved.
******************************************************/

#include <iostream>
#define SIZE 5

using namespace std;

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

template <typename T>
struct Queue
{
	T elems[SIZE]{};
	// front是队列的头，rear是队列的尾，初始值为-1或者0都可，只是处理思路不同，推荐-1
	int front = 0;	//front指向队列头元素
	int rear = 0;	//rear指向队列尾元素下一位
	int count = 0;	//标记队列中元素个数，来处理循环队列中头尾相遇无法判断的问题
	void inQueue(T elem)
	{
		/* ⼊队列操作 */
		elems[rear] = elem;
		rear = (rear + 1) % SIZE;
		count++;
	}
	T deQueue()
	{
		/* 出队列操作 */
		T elem = elems[front];
		front = (front + 1) % SIZE;
		count--;
		return elem;
	}
	bool isEmpty()
	{
		/* 判断队列是否为空，思考⼀下什么时候需要调⽤该函数？同时要想清楚队列为空的条件（与栈
	   不太⼀样，isFull也⼀样需要考虑清楚） */
		if (count <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		/* 判断队列是否已满，思考⼀下什么时候需要调⽤该函数？ */
		if (count >= SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void print()
	{
		/* 打印当前队列内元素，格式如下（分别以T为string、Point时，以及队列为空举例）：
		[today,is,a,good,day,]
		[(1,2),(3,4),(7,8),]
		[]
		左边为队头，右边为队尾。为⽅便循环处理，栈顶元素后⾯的逗号⽆需去除
		*/
		cout << '[';
		for (int i = front; count > 0; count--)
		{
			cout << elems[i] << ',';
			i = (i + 1) % SIZE;
		}
		cout << ']' << endl;
	}
};

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
