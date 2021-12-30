#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

void toPostfix(char[]);

int main()
{
	char str[100];

	while (true)
	{
		// ((A*B)-(C/D)) 을 입력해 AB*CD/-이 출력되는지 확인
		cout << "후위 표기법으로 변환할 문자열을 입력하세요." << endl
			<< "'0'을 입력하면 프로그램이 종료됩니다." << endl;
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
		case '+': case '-': case '*': case '/': // 연산자 처리 : 스택에 push
			stack.Push(currChar);
			break;
		case '(':								// 왼쪽 괄호는 무시하고 다음 문자 읽기
			break;
		case ')':								// 오른쪽 괄호 처리 : 스택을 pop하여 출력
			cout << stack.Pop();
			break;
		case NULL:								// 수식의 끝 처리
			while (stack.IsEmpty() != true)		// 스택이 공백이 될 때까지 pop하여 출력
			{
				cout << stack.Pop();
			}
			return;
		default:								// 피연산자 처리 : 출력
			cout << currChar;
		}
		i++;
	}
}