#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

DLinkedList::DLinkedList(void)
{
	Head = NULL;
	Tail = NULL;
}

DLinkedList::~DLinkedList(void)
{
	RemoveAll();
}

// 노드 추가

void DLinkedList::Add(int Item)
{
	NODE *temp = new NODE;

	temp->Data = Item;
	temp->Prev = NULL; // DLinkedList 추가
	temp->Next = NULL;
	
	/*
	과제 :
	Add(int Item); 함수에서 위의 Exist() 함수를 호출해 리스트에 이미 있는 Item이 들어오면 아래 에러 문구를 출력하고 반환하도록 수정
	*/
	bool exist = Exist(Item);
	if (exist == true)
	{
		cout << "입력한 " << Item << "은 이미 리스트에 등록되어 있습니다." << endl;
		return;
	}

	if (Head == NULL)
	{
		Head = temp;
		Tail = temp;
	}
	else
	{
		Tail->Next = temp;
		temp->Prev = Tail; // DLinkedList 추가
		Tail = temp;
	}
}

// 노드 삭제
void DLinkedList::Remove(int Item)
{
	if (Head == NULL)
	{
		cout << "비어 있는 리스트입니다." << endl;
		return;
	}

	NODE *temp = Head;
	NODE *prev = NULL;

	// 삭제 대상 노드를 찾음
	while (temp != NULL && temp->Data != Item)
	{
		prev = temp;
		temp = temp->Next;
	}

	// 삭제 대상 노드가 없음
	if (temp == NULL)
	{
		cout << "삭제할 노드가 없습니다." << endl;
		return;
	}

	// temp가 한번도 전진하지 않았음 => 삭제 대상이 첫 노드임
	if (prev == NULL)
	{
		Head = Head->Next;

		// DLinkedList 추가
		if (Head != NULL)
			Head->Prev = NULL; 
		
		delete temp;
	}
	else // 삭제 대상이 있음
	{
		prev->Next = temp->Next;

		// DLinkedList 추가
		if (temp->Next != NULL)
			temp->Next->Prev = prev;

		if (prev->Next == NULL)
			Tail = prev;

		delete temp;
	}
}

void DLinkedList::RemoveLastNode()
{
	if (Head == NULL)
	{
		cout << "비어 있는 리스트입니다." << endl;
		return;
	}

	NODE *temp = Head;
	NODE *prev = NULL;
		
	// 리스트에 노드가 하나만 있는 경우 첫 번째 노드 삭제
	if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		return;
	}
	else
	{
		// prev = Head;
		// temp = Head->Next;

		// while (temp->Next != NULL)
		// {
		//		prev = temp;
		//		temp = temp->Next;
		//	}

		// delete temp;
		// prev->Next = NULL;

		// DLinkedList 수정
		prev = Tail->Prev;
		prev->Next = NULL;

		delete Tail;
		Tail = prev;
	}
}

void DLinkedList::RemoveAll()
{
	NODE *temp = Head;

	while (Head != NULL)
	{
		temp = Head;
		Head = Head->Next;
		delete temp;
		temp = NULL;
	}

	Tail = NULL;
}

// 전체 노드 개수
int DLinkedList::Count()
{
	int count = 0;
	NODE *temp = Head;

	while (temp != NULL)
	{
		count++;
		temp = temp->Next;
	}

	return count;
}

// 모든 노드 출력
void DLinkedList::PrintAllList()
{
	cout << "List = (";
	NODE *temp = Head;

	while (temp != NULL)
	{
		cout << temp->Data;
		temp = temp->Next;

		if (temp != NULL)
			cout << ", ";
	}

	cout << ")" << endl;
}

// 모든 노드 반대로 출력
void DLinkedList::PrintAllListReverse()
{
	cout << "Reverse List = (";
	// NODE *temp = Head;
	NODE *temp = Tail; // DLinkedList 수정

	while (temp != NULL)
	{
		cout << temp->Data;
		temp = temp->Prev; // DLinkedList 수정

		if (temp != NULL)
			cout << ", ";
	}

	cout << ")" << endl;
}

/*
	과제 :
	bool Exist(int Item); 함수를 추가해서 Item이 이미 리스트에 있으면 true를 반환하고 없으면 false를 반환 하도록 구현
*/
bool DLinkedList::Exist(int Item)
{
	bool exist = false; // exist라는 bool 변수를 선언 및 초기화
	NODE *temp = Head; // temp라는 NODE를 가리키는 포인터 선언 및 초기화

	while (temp != NULL)
	{
		if (temp->Data == Item) // 리스트의 요소를 Item값과 하나씩 비교한다.
		{
			exist = true; // 만약 같은 값이 존재한다면 exist를 true값으로 변경한다.
			break;
		}
		temp = temp->Next; // 비교를 마친 후 다음 리스트 요소를 가리키도록 한다. 
	}

	temp = NULL; // 사용을 마친 포인터 temp의 값은 NULL로 초기화 시켜놓는다.
	return exist;
}

/*
	과제 :
	함수를 추가한 후 아래 기능 구현
	• 현재 리스트에서 TargetItem이 없으면 에러 문구 출력 후 반환
	• TargetItem이 리스트에 있으면 해당 노드 다음에 Item을 가지는 노드를 동적 생성해 연결
*/
void DLinkedList::InsertAfter(int TargetItem, int Item)
{
	NODE *temp = Head;
	NODE *newtemp = new NODE;			// 삽입할 노드를 생성한다.
	while (temp != NULL)
	{
		if (temp->Data == TargetItem && temp != Tail) // 새 노드가 중간에 들어가는 경우
		{
			newtemp->Data = Item;				 // 새 노드의 데이터 필드에 값을 저장한다.
			newtemp->Next = temp->Next;			 // 새 노드의 왼쪽 노드의 오른쪽 링크를 새 노드의 오른쪽 링크에 저장한다.
			temp->Next = newtemp;				 // 왼쪽 노드의 오른쪽 링크에 새 노드의 주소를 저장한다.
			newtemp->Prev = newtemp->Next->Prev; // 새 노드의 오른쪽 노드의 왼쪽 링크를 새 노드의 왼쪽 링크에 저장한다.
			newtemp->Next->Prev = newtemp;		 // 오른쪽 노드의 왼쪽 링크에 새 노드의 주소를 저장한다.
			return;
		}
		else if (temp->Data == TargetItem && temp == Tail) // 새 노드가 리스트의 마지막에 들어가는 경우
		{
			newtemp->Data = Item; // 새 노드의 데이터 필드에 값을 저장한다.
			newtemp->Next = NULL; // NULL값(Tail노드의 오른쪽 링크 값)을 새 노드의 오른쪽 링크에 저장한다.
			Tail->Next = newtemp; // 왼쪽 노드(기존 Tail 노드)의 오른쪽 링크에 새 노드의 주소를 저장한다.
			newtemp->Prev = Tail; // 왼쪽 노드(기존 Tail 노드)를 새 노드의 왼쪽 링크에 저장한다.
			Tail = newtemp;		  // 새로운 노드를 Tail에 저장한다.
			return;
		}
		temp = temp->Next;
	}
	cout << "입력된 " << TargetItem << "은 리스트에 없습니다." << endl;
	delete newtemp; // TargetItem을 찾지 못한 경우 동적 할당된 newtemp Node의 메모리를 해제시킨다.
	temp = NULL; // 사용을 마친 포인터 temp의 값은 NULL로 초기화 시켜놓는다.
}

/*
	과제 :
	함수를 추가한 후 아래 기능 구현
	• 현재 리스트에서 TargetItem이 없으면 에러 문구 출력 후 반환
	• TargetItem이 리스트에 있으면 해당 노드 이전에 Item을 가지는 노드를 동적 생성해 연결
*/
void DLinkedList::InsertBefore(int TargetItem, int Item)
{
	NODE *temp = Head;
	NODE *newtemp = new NODE;			// 삽입할 노드를 생성한다.
	while (temp != NULL)
	{
		if (temp->Data == TargetItem && temp != Head) // 새 노드가 중간에 들어가는 경우
		{
			newtemp->Data = Item;				// 새 노드의 데이터 필드에 값을 저장한다.
			newtemp->Next = temp->Prev->Next;	// 새 노드의 왼쪽 노드의 오른쪽 링크를 새 노드의 오른쪽 링크에 저장한다.
			temp->Prev->Next = newtemp;			// 왼쪽 노드의 오른쪽 링크에 새 노드의 주소를 저장한다.
			newtemp->Prev = temp->Prev;			// 새 노드의 오른쪽 노드의 왼쪽 링크를 새 노드의 왼쪽 링크에 저장한다.
			temp->Prev = newtemp;				// 오른쪽 노드의 왼쪽 링크에 새 노드의 주소를 저장한다.
			return;
		}
		else if (temp->Data == TargetItem && temp == Head) // 새 노드가 리스트의 처음에 들어가는 경우
		{
			newtemp->Data = Item; // 새 노드의 데이터 필드에 값을 저장한다.
			newtemp->Prev = NULL; // NULL값(Head노드의 왼쪽 링크 값)을 새 노드의 왼쪽 링크에 저장한다.
			Head->Prev = newtemp; // 오른쪽 노드(기존 Head 노드)의 왼쪽 링크에 새 노드의 주소를 저장한다.
			newtemp->Next = Head; // 오른쪽 노드(기존 Head 노드)를 새 노드의 오른쪽 링크에 저장한다. 
			Head = newtemp;		  // 새로운 노드를 Head에 저장한다.
			return;
		}

		temp = temp->Next;
	}
	cout << "입력된 " << TargetItem << "은 리스트에 없습니다." << endl;
	delete newtemp; // TargetItem을 찾지 못한 경우 동적 할당된 newtemp Node의 메모리를 해제시킨다.
	temp = NULL; // 사용을 마친 포인터 temp의 값은 NULL로 초기화 시켜놓는다.
}