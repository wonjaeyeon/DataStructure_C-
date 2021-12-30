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
};