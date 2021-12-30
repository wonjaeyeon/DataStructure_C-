#pragma once
/*
- task1�� ���� ���� ����Ʈ�� �����Ͽ� �ּҷ��� �����ϴ� ���α׷����� ����
- DoubleLinkedList.h ������ nodeRecord ����ü�� Data ��� ������ �ּҷ��� ����� �̸��� ��ȭ��ȣ�� ������ ����ü�� ����
*/
typedef struct nodeData
{
	char name[20]; // �̸�
	char phone[14]; // "010-9895-3138"
} NODE_DATA;

typedef struct nodeRecord
{
	struct nodeRecord *Prev; // DLinkedList �߰�
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

	// ��� �߰�
	/*
	���� :
	- Add(int Item) �Լ��� Add(char name[], char phone[])���� ���ڸ� ����
	*/
	void Add(char name[], char phone[]);

	// ��� ����
	/*
	���� :
	- Remove(int Item) �Լ��� Remove(char phone[])���� ���ڸ� ����
	*/
	void Remove(char phone[]);
	void RemoveLastNode();
	void RemoveAll();

	// ��ü ��� ����
	int Count();

	// ��� ��� ���
	void PrintAllList();

	// ��� ��� �ݴ�� ���
	void PrintAllListReverse(); // DLinkedList �߰�

	/*���� : (task1)*/
	bool Exist(char name[], char phone[]);
	void InsertAfter(int TargetItem, int Item);
	void InsertBefore(int TargetItem, int Item);
};