#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

bool testPair(char[]);

int main()
{
	char str[100];

	while (true)
	{
		// (a*b)-(c+d) 을 입력해 1 이 출력되는지 확인
		// (a*b)-(c+d 을 입력해 0 이 출력되는지 확인
		cout << "검사할 수식을 입력하세요." << endl
	 		 << "'0'을 입력하면 프로그램이 종료됩니다." << endl;
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
		case '(': case '[': case '{':	// 왼쪽 괄호를 만나면 스택에 push한다.
			stack.Push(str[i]);
			break;
		case ')':						// 오른쪽 괄호를 만나면 스택의 GetTop함수를 이용하여 마지막에 저장한 괄호와 같은 종류인지를 확인한다.
			if (stack.GetTop() == '(')
			{
				stack.Pop();			// 만약 같다면 스택을 Pop하여 마지막에 저장한 노드를 삭제한다.
				break;
			}
			else
			{
				return false;			// 만약 같지 않다면 괄호의 짝이 잘못 사용된 수식이므로 false값을 반환한다.
			}
			break;
		case ']':						// 오른쪽 괄호를 만나면 스택의 GetTop함수를 이용하여 마지막에 저장한 괄호와 같은 종류인지를 확인한다.
			if (stack.GetTop() == '[')
			{
				stack.Pop();			// 만약 같다면 스택을 Pop하여 마지막에 저장한 노드를 삭제한다.
				break;
			}
			else
			{
				return false;			// 만약 같지 않다면 괄호의 짝이 잘못 사용된 수식이므로 false값을 반환한다.
			}
			break;
		case '}':						// 오른쪽 괄호를 만나면 스택의 GetTop함수를 이용하여 마지막에 저장한 괄호와 같은 종류인지를 확인한다.
			if (stack.GetTop() == '{')	
			{
				stack.Pop();			// 만약 같다면 스택을 Pop하여 마지막에 저장한 노드를 삭제한다.
				break;
			}
			else
			{
				return false;			// 만약 같지 않다면 괄호의 짝이 잘못 사용된 수식이므로 false값을 반환한다.
			}
			break;
		case NULL:						// 수식에 대한 검사가 모두 끝났을 스택이 공백인지 확인한다.
			if (stack.IsEmpty() == true)
				return true;			// 스택이 공백이면 괄호의 짝이 제대로 사용된 수식이므로 true를 반환한다.
			else
				return false;			// 스택이 공백이 아니면 괄호의 짝이 잘못 사용된 수식이므로 false를 반환한다.
		}
		i++;
	}
}