#pragma once
/*
- task1의 이중 연결 리스트를 변형하여 주소록을 관리하는 프로그램으로 수정
- DoubleLinkedList.h 파일의 nodeRecord 구조체의 Data 멤버 변수를 주소록의 사람의 이름과 전화번호를 저장할 구조체로 변경
*/
typedef struct nodeData
{
	char name[20]; // 이름
	char phone[14]; // "010-9895-3138"
} NODE_DATA;

typedef struct nodeRecord
{
	struct nodeRecord *Prev; // DLinkedList 추가
	// int Data;
	NODE_DATA Data;
	struct nodeRecord *Next;
} NODE;

class DLinkedList
{
private:
	NODE *Head, *Tail;

public:
	DLinkedList(void);
	~DLinkedList(void);

	// 노드 추가
	/*
	과제 :
	- Add(int Item) 함수를 Add(char name[], char phone[])으로 인자를 수정
	*/
	void Add(char name[], char phone[]);

	// 노드 삭제
	/*
	과제 :
	- Remove(int Item) 함수를 Remove(char phone[])으로 인자를 수정
	*/
	void Remove(char phone[]);
	void RemoveLastNode();
	void RemoveAll();

	// 전체 노드 개수
	int Count();

	// 모든 노드 출력
	void PrintAllList();

	// 모든 노드 반대로 출력
	void PrintAllListReverse(); // DLinkedList 추가

	/*과제 : (task1)*/
	bool Exist(char name[], char phone[]);
	void InsertAfter(int TargetItem, int Item);
	void InsertBefore(int TargetItem, int Item);
};