/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem2 ����ָ�� */
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
#include <windows.h>
using namespace std;

int add(int a, int b)
{
	return a + b;
}
int subtract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}

int calc(int a, int b, int(*p_func)(int, int))
{
	return p_func(a, b);
}

int main()
{
	string str;	//�����
	int switchOn;
	int a, b;
	cin >> str >> a >> b;

	if (str == "add")	//�ƺ��޷�ֱ��switch-case string���ͣ��ʳ����²�
	{
		switchOn = 1;
	}
	else if (str == "subtract")
	{
		switchOn = 2;
	}
	else if (str == "multiply")
	{
		switchOn = 3;
	}
	else if (str == "divide")
	{
		switchOn = 4;
	}
	else
	{
		MessageBoxA(GetForegroundWindow(), "�����������˴��������������������(��������)��\n������֪�������ť���رճ�����", "��Ү�����������", 4);
		return EXIT_FAILURE;
	}

	switch (switchOn)
	{
		case 1:
			cout << calc(a, b, add) << endl;
			break;
		case 2:
			cout << calc(a, b, subtract) << endl;
			break;
		case 3:
			cout << calc(a, b, multiply) << endl;
			break;
		case 4:
			cout << calc(a, b, divide) << endl;
			break;
		default:
			return EXIT_FAILURE;
	}

	return 0;
}

/*
����ָ�봫�Σ�ͨ��һ�����ú����ĺ�����������Ҫ���������õĺ�����
�ŵ㣺�Բ�ͬ�����ľ�������ں����ڲ����޸�ʱֻ��Ҫ�޸Ĵ���ʱ����ĺ���������ε���ʱֻ���޸�һ�Σ�
	  �����ʵ�ֺ͵��÷��룬����ģ�黯��̣�
ȱ�㣺�������õľ������ò����ԣ�ȱ��ֱ����;
	  �����õĺ������뷵�����ͺͲ���������ͬ���޷���Բ�ͬ�������������أ�

ֱ�ӵ��ò�ͬ������ֱ�Ӹ��ݲ�ͬ���������ú�����
�ŵ㣺���Խ������أ����䲻ͬ�������ͣ�
ȱ�㣺�Բ�ͬ�����ľ�������ں����ⲿ���޸�ʱ������Ҫ�ظ��޸ģ�
*/