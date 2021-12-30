#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

bool testPair(char[]);

int main()
{
	char str[100];

	while (true)
	{
		// (a*b)-(c+d) �� �Է��� 1 �� ��µǴ��� Ȯ��
		// (a*b)-(c+d �� �Է��� 0 �� ��µǴ��� Ȯ��
		cout << "�˻��� ������ �Է��ϼ���." << endl
	 		 << "'0'�� �Է��ϸ� ���α׷��� ����˴ϴ�." << endl;
		cin >> str;

		if (str[0] == '0')
			return 0;

		bool result = testPair(str);

		cout << result << endl;
	}

	return 0;
}

bool testPair(char str[])
{
	StackByLinkedList stack;

	int i = 0;
	while (true)
	{
		char currChar = str[i];

		switch (currChar) 
		{
		case '(': case '[': case '{':	// ���� ��ȣ�� ������ ���ÿ� push�Ѵ�.
			stack.Push(str[i]);
			break;
		case ')':						// ������ ��ȣ�� ������ ������ GetTop�Լ��� �̿��Ͽ� �������� ������ ��ȣ�� ���� ���������� Ȯ���Ѵ�.
			if (stack.GetTop() == '(')
			{
				stack.Pop();			// ���� ���ٸ� ������ Pop�Ͽ� �������� ������ ��带 �����Ѵ�.
				break;
			}
			else
			{
				return false;			// ���� ���� �ʴٸ� ��ȣ�� ¦�� �߸� ���� �����̹Ƿ� false���� ��ȯ�Ѵ�.
			}
			break;
		case ']':						// ������ ��ȣ�� ������ ������ GetTop�Լ��� �̿��Ͽ� �������� ������ ��ȣ�� ���� ���������� Ȯ���Ѵ�.
			if (stack.GetTop() == '[')
			{
				stack.Pop();			// ���� ���ٸ� ������ Pop�Ͽ� �������� ������ ��带 �����Ѵ�.
				break;
			}
			else
			{
				return false;			// ���� ���� �ʴٸ� ��ȣ�� ¦�� �߸� ���� �����̹Ƿ� false���� ��ȯ�Ѵ�.
			}
			break;
		case '}':						// ������ ��ȣ�� ������ ������ GetTop�Լ��� �̿��Ͽ� �������� ������ ��ȣ�� ���� ���������� Ȯ���Ѵ�.
			if (stack.GetTop() == '{')	
			{
				stack.Pop();			// ���� ���ٸ� ������ Pop�Ͽ� �������� ������ ��带 �����Ѵ�.
				break;
			}
			else
			{
				return false;			// ���� ���� �ʴٸ� ��ȣ�� ¦�� �߸� ���� �����̹Ƿ� false���� ��ȯ�Ѵ�.
			}
			break;
		case NULL:						// ���Ŀ� ���� �˻簡 ��� ������ ������ �������� Ȯ���Ѵ�.
			if (stack.IsEmpty() == true)
				return true;			// ������ �����̸� ��ȣ�� ¦�� ����� ���� �����̹Ƿ� true�� ��ȯ�Ѵ�.
			else
				return false;			// ������ ������ �ƴϸ� ��ȣ�� ¦�� �߸� ���� �����̹Ƿ� false�� ��ȯ�Ѵ�.
		}
		i++;
	}
}