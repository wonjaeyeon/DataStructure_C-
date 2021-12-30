#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

void toPostfix(char[]);

int main()
{
	char str[100];

	while (true)
	{
		// ((A*B)-(C/D)) �� �Է��� AB*CD/-�� ��µǴ��� Ȯ��
		cout << "���� ǥ������� ��ȯ�� ���ڿ��� �Է��ϼ���." << endl
			<< "'0'�� �Է��ϸ� ���α׷��� ����˴ϴ�." << endl;
		cin >> str;

		if (str[0] == '0')
			return 0;

		toPostfix(str);

		cout << endl;
	}

	return 0;
}

void toPostfix(char str[])
{
	StackByLinkedList stack;

	int i = 0;
	while (true)
	{
		char currChar = str[i];

		switch (currChar)
		{
		case '+': case '-': case '*': case '/': // ������ ó�� : ���ÿ� push
			stack.Push(currChar);
			break;
		case '(':								// ���� ��ȣ�� �����ϰ� ���� ���� �б�
			break;
		case ')':								// ������ ��ȣ ó�� : ������ pop�Ͽ� ���
			cout << stack.Pop();
			break;
		case NULL:								// ������ �� ó��
			while (stack.IsEmpty() != true)		// ������ ������ �� ������ pop�Ͽ� ���
			{
				cout << stack.Pop();
			}
			return;
		default:								// �ǿ����� ó�� : ���
			cout << currChar;
		}
		i++;
	}
}