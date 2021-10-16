/* !!!Please open by ANSI if random codes appeared!!! */
/* 2052336 ��Ʒ� */
/* Problem3 ë��ļ����� */
/* ��ʹ��MSVC������(VS2019)��Realease x64���У�����������(������������GCC(DevC++)��Clang)���ܻ����ʧ�ܻ������������ */

#include <iostream>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <stack>
using namespace std;

#pragma region �۵�����_�߾����㷨_������ʱΪ�;���

/// <summary>
/// ȥ�����ţ��������Ƿ���
/// </summary>
/// <param name="strNum">���ַ�����ʾ������</param>
/// <returns>�Ƿ�Ϊ����</returns>
bool removeMinus(string& strNum)
{
	if (strNum[0] == '-')
	{
		strNum = strNum.substr(1, strNum.length() - 1);
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// �߾��ȼӷ�
/// </summary>
/// <param name="add1">����1���Ǹ�</param>
/// <param name="add2">����2���Ǹ�</param>
/// <returns>�ͣ��Ǹ�</returns>
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

/// <summary>
/// �߾��ȼ���
/// </summary>
/// <param name="rdc1">���������Ǹ�</param>
/// <param name="rdc2">�������Ǹ�</param>
/// <returns>�������</returns>
string highPrecisionReduce(string rdc1, string rdc2)
{
	bool isNegative = false;
	/*�ַ���Ԥ����*/
	if (rdc1.length() < rdc2.length() || (rdc1.length() == rdc2.length() && rdc1 < rdc2))	//��������,ʹ�����ǰ
	{
		swap(rdc1, rdc2);
		isNegative = true;
	}
	int deltaLen = (int)(rdc1.length() - rdc2.length());
	for (int i = 0; i < deltaLen; i++)	//��0
	{
		rdc2 = "0" + rdc2;
	}
	/*���м�������*/
	string result;
	bool borrow = false;	//��λ
	for (int i = (int)max(rdc1.length(), rdc2.length()) - 1; i >= 0; i--)
	{
		int a = rdc1[i] - '0';	//�ַ�תΪ����
		int b = rdc2[i] - '0';
		int delta = a - b - borrow;

		if (delta < 0)
		{
			borrow = true;
			delta += 10;
		}
		else
		{
			borrow = false;
		}

		result += (delta + '0');
	}
	/* ɾ�����λ��0 */
	while (result.length() != 1 && result[result.length() - 1] == '0')
	{
		result.pop_back();
	}
	reverse(result.begin(), result.end());	//��ת�ַ���
	if (isNegative)
	{
		result = "-" + result;
	}
	return result;
}

/// <summary>
/// �߾��ȳ˷�
/// </summary>
/// <param name="mut1">����1����������</param>
/// <param name="mut2">����2����������</param>
/// <returns>����������</returns>
string highPrecisionMutil(string mut1, string mut2)
{
	string result;
	bool isNegative1 = removeMinus(mut1);
	bool isNegative2 = removeMinus(mut2);
	/* ����洢 */
	int len1 = (int)mut1.length();
	vector<int> num1(len1);
	for (int i = 0; i < len1; i++)
	{
		num1[i] = mut1[len1 - i - 1] - '0';
	}
	int len2 = (int)mut2.length();
	vector<int> num2(len2);
	for (int i = 0; i < len2; i++)
	{
		num2[i] = mut2[len2 - i - 1] - '0';
	}

	int carry = 0;	//��λ
	vector<int> product(len1 + len2 + 1);
	for (int i = 0; i < len1; i++)
	{
		int carry = 0;
		for (int j = 0; j < len2; j++)
		{
			product[i + j] = product[i + j] + num1[i] * num2[j] + carry;
			carry = product[i + j] / 10;
			product[i + j] = product[i + j] % 10;
		}
		product[i + len2] = carry;         //��λ
	}
	for (int i = 0; i < len1 + len2 + 1; i++)
	{
		result = result + (char)(product[i] + '0');
	}

	/* ɾ�����λ��0 */
	while (result.length() != 1 && result[result.length() - 1] == '0')
	{
		result.pop_back();
	}

	reverse(result.begin(), result.end());	//��ת�ַ���
	if (isNegative1 != isNegative2)
	{
		result = '-' + result;
	}
	return result;
}
#pragma endregion

/// <summary>
/// �����ַ����з����ֵ�λ��
/// </summary>
/// <param name="str">�ַ���</param>
/// <param name="startPos">������ʼλ��</param>
/// <returns>�����ֵ�λ�ã�δ�ҵ�����-1</returns>
int findNonDigit(string str, int startPos = 0)
{
	for (int i = startPos; i < str.length(); i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// �ָ��ַ���Ϊ���֣������
/// </summary>
/// <param name="result">��ŷָ����ַ��������ֺ��������ռһ��Ԫ��</param>
/// <param name="str">Ҫ�ָ���ַ���</param>
void splitDigitAndOperator(vector<string>& result, string str)
{
	int startPos = 0;
	int endPos = findNonDigit(str);
	while (true)
	{
		/* ���ֽ�ջ */
		if (endPos == -1)
		{
			result.push_back(str.substr(startPos, str.length() - startPos));
			break;
		}
		else
		{
			result.push_back(str.substr(startPos, endPos - startPos));
			result.push_back(str.substr(endPos, 1));
			startPos = endPos + 1;
			endPos = findNonDigit(str, startPos);
		}
	}
}

/// <summary>
/// ��������������ȼ�
/// </summary>
/// <param name="ope">�����</param>
/// <returns>���ȼ�</returns>
int operatorLevel(char ope)
{
	if (ope == '*' || ope == '/' || ope == '%')
	{
		return 5;
	}
	else if (ope == '+' || ope == '-')
	{
		return 6;
	}
	return -1;
}

/// <summary>
/// �Ƚ�����������ȼ�
/// </summary>
/// <param name="ope1">�����1</param>
/// <param name="ope2">�����2</param>
/// <returns>���ȼ���ֵ�������1���ȼ��ͷ�������</returns>
int operatorCompare(char ope1, char ope2)
{
	return operatorLevel(ope1) - operatorLevel(ope2);
}

/// <summary>
/// ������ʽ����֧��+-*/
/// </summary>
/// <param name="ope">�����</param>
/// <param name="num1">����1</param>
/// <param name="num2">����2</param>
/// <returns>�����Ƿ����ɹ�</returns>
bool computer(char ope, string num1, string num2, string& result)
{
	if (ope == '*')
	{
		result = highPrecisionMutil(num1, num2);
		return true;
	}
	else if (ope == '/')
	{
		if (num2 == "0")
		{
			cout << "error";
			return false;
		}
		char temp[10];
		char* p = temp;

		result = to_string(strtoll(num1.c_str(), &p, 10) / strtoll(num2.c_str(), &p, 10));

		return true;
	}
	else if (ope == '+' || ope == '-')
	{
		if (ope == '+')
		{
			bool isNegative1 = removeMinus(num1);
			bool isNegative2 = removeMinus(num2);
			if (isNegative1 == true && isNegative2 == true)	//����
			{
				result = highPrecisionAdd(num1, num2);
				result = "-" + result;
				return true;
			}
			if (isNegative1 == false && isNegative2 == true)	//�ڶ��������൱�ڼ�
			{
				result = highPrecisionReduce(num1, num2);
				return true;
			}
			if (isNegative1 == true && isNegative2 == false)	//��һ�������൱�ڵڶ�������һ��
			{
				result = highPrecisionReduce(num2, num1);
				return true;
			}
			if (isNegative1 == false && isNegative2 == false)	//����
			{
				result = highPrecisionAdd(num1, num2);
				return true;
			}
		}
		if (ope == '-')
		{
			bool isNegative1 = removeMinus(num1);
			bool isNegative2 = removeMinus(num2);
			if (isNegative1 == true && isNegative2 == true)	//����,�൱�ڵڶ�������һ��
			{
				result = highPrecisionReduce(num2, num1);
				return true;
			}
			if (isNegative1 == false && isNegative2 == true)	//�ڶ��������൱�ڼ�
			{
				result = highPrecisionAdd(num1, num2);
				return true;
			}
			if (isNegative1 == true && isNegative2 == false)	//��һ�������൱�ڼӣ����ȡ��
			{
				result = highPrecisionAdd(num1, num2);
				result = "-" + result;
				return true;
			}
			if (isNegative1 == false && isNegative2 == false)	//����
			{
				result = highPrecisionReduce(num1, num2);
				return true;
			}
		}
	}

	return false;

}

/// <summary>
/// ����ջ��һ�μ���
/// </summary>
/// <param name="operatorStack">�����ջ</param>
/// <param name="numStack">����ջ</param>
/// <returns></returns>
bool stackComputer(stack<char>& operatorStack, stack<string>& numStack)
{
	/* ���ȼ��ͻ���ȣ�ջ���������ջ1��������ջ��ջ2���������������ջ��ջ1�� */
	char op = operatorStack.top();
	operatorStack.pop();
	string num1 = numStack.top();
	numStack.pop();
	string num2 = numStack.top();
	numStack.pop();
	string result;

	if (!computer(op, num2, num1, result))
	{
		return false;
	}
	numStack.push(result);

	return true;
}

int main()
{
	string input;
	cin >> input;

	vector<string> elements;
	splitDigitAndOperator(elements, input);	//�ָ��ַ���

	stack<string> numStack;		//����ջ
	stack<char> operatorStack;	//�����ջ

	char temp[10];
	char* p = temp;
	/* �Ƚ�ջ */
	numStack.push(elements[0]);
	operatorStack.push(elements[1][0]);
	numStack.push(elements[2]);

	/* ѭ���Ƚ����ȼ���ջ */
	int pos = 3;	//�������λ��Ϊ����
	while (pos < elements.size())
	{
		if (operatorStack.size() == 0 || operatorCompare(operatorStack.top(), elements[pos][0]) > 0)
		{
			/* ���ȼ��ߣ���ջ */
			operatorStack.push(elements[pos][0]);
			numStack.push(elements[pos + 1]);
			pos += 2;
		}
		else
		{
			if (!stackComputer(operatorStack, numStack))
			{
				return -1;
			}
		}
	}

	/* �������գ�����ջ */
	while (numStack.size() != 1)
	{
		if (!stackComputer(operatorStack, numStack))
		{
			return -1;
		}
	}
	string result;
	result = numStack.top();
	if (result.length() > 6)
	{
		bool isNegative = removeMinus(result);
		if (isNegative)
		{
			result = "-" + result.substr(result.length() - 6);
		}
		else
		{
			result = result.substr(result.length() - 6);
		}
	}
	cout << atoi(result.c_str()) % 10000 << endl;

	return 0;
}