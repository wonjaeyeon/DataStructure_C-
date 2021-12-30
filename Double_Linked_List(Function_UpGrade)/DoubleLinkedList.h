#pragma once

typedef struct nodeRecord
{
	struct nodeRecord *Prev; // DLinkedList �߰�
	int Data;
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
	void Add(int Item);

	// ��� ����
	void Remove(int Item);
	void RemoveLastNode();
	void RemoveAll();

	// ��ü ��� ����
	int Count();

	// ��� ��� ���
	void PrintAllList();

	// ��� ��� �ݴ�� ���
	void PrintAllListReverse(); // DLinkedList �߰�

	/*���� : (task1)*/
	bool Exist(int Item);
	void InsertAfter(int TargetItem, int Item);
	void InsertBefore(int TargetItem, int Item);
};