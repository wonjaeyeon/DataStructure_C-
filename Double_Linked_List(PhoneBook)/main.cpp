#include <iostream>
#include <cstring>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{
	DLinkedList list1;
	char name[20];
	char phone[14];
	char answer[20];

	while (true)
	{
		cout << "�̸��� �Է��Ͻÿ�. : ";
		cin >> name;
		cout << endl;
		cout << "��ȭ��ȣ�� �Է��Ͻÿ�. : ";
		cin >> phone;
		cout << endl;
		list1.Add(name, phone);
		cout << "�̸��� ��ȭ��ȣ�� �� �߰��ϰڽ��ϱ�?" << endl;
		cin >> answer;
		const char *a = answer;
		if (strcmp(a, "yes") == 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	list1.PrintAllList();

	return 0;
}