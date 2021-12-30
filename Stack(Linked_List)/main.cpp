#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

int main()
{
	StackByLinkedList stack;
	char str[100];

	cout << "�Ųٷ� ����� ���ڸ� �����ڷ� �Է��ϼ���." << endl;
	cin >> str;

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '\0')
			break;
		else
			stack.Push(str[i]);
	}

	int count = stack.GetSize();
	for (int i = 0; i < count; i++)
	{
		cout << stack.Pop();
	}

	return 0;
}
