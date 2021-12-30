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
		cout << "이름을 입력하시오. : ";
		cin >> name;
		cout << endl;
		cout << "전화번호를 입력하시오. : ";
		cin >> phone;
		cout << endl;
		list1.Add(name, phone);
		cout << "이름과 전화번호를 더 추가하겠습니까?" << endl;
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