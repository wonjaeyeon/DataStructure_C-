#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

NODE_TREE *BinarySearchTree::searchBST(NODE_TREE *node, element x)
{
	// 과제 : searchBST() 함수 구현
	// 슈도 코드를 참고해 구현하세요.
	NODE_TREE *p = node;
	if (p == NULL)							// 트리에 루트노드가 없는 경우
		return NULL;
	else if (x == p->key)					// X 값과 노드의 키값이 같은 경우 : 원하는 원소 찾았으므로 포인터 p값을 반환한다.
		return p;
	else if (x < p->key)					// X 값이 노드의 키값보다 작은 경우 : 노드의 왼쪽 서브트리에 대해서 탐색연산을 수행한다.
		return searchBST(p->left, x);
	else									// X 값이 노드의 키값보다 큰 경우 : 노드의 오른쪽 서브트리에 대해서 탐색연산을 수행한다.
		return searchBST(p->right, x);
}

void BinarySearchTree::insertNode(element x)
{
	// 과제 : insertNode() 함수 구현
	// 슈도 코드를 참고해 구현하세요.
	NODE_TREE *p = getRoot();				// 포인터 p를 루트 노드의 주소값으로 초기화한다. while문을 통한 탐색연산을 해야하기 때문이다.
	NODE_TREE *q = NULL;					// 포인터 q를 NULL 값으로 초기화한다. 포인터 q는 삽입할 노드의 부모 노드의 주소값을 저장하기 위해 사용된다.
	while (p != NULL)						// <포인터 p를 이용해 삽입할 자리를 탐색한다.>
	{
		if (x == p->key)					// X 값과 노드의 키값이 같은 경우 : 원하는 자리(삽입할 자리)를 찾았으므로  break를 통해 반복문을 빠져나온다.
			break;
		q = p;								// 포인터 q에 삽입할 노드의 부모 노드의 주소값을 넣는다. 
		if (x < p->key)						// X 값이 노드의 키값보다 작은 경우 : 노드의 왼쪽 서브트리에 대해서 탐색한다.
			p = p->left;
		else								// X 값이 노드의 키값보다 큰 경우 : 노드의 오른쪽 서브트리에 대해서 탐색한다.
			p = p->right;
	}

	NODE_TREE* a = makeNode(x, NULL, NULL); // <삽입할 노드를 생성한다.> : 새로 만든 노드의 키값은 x, 왼쪽,오른쪽 링크 필드에는 NULL값을 넣는다. 

	p = getRoot();							// <탐색한 자리에 노드를 연결한다.>
	if (p == NULL)							// 루트노드가 없는 경우 : 루트노드로 노드 a를 삽입한다.
		setRoot(a);
	else if (x < q->key)					// x의 값이 노드의 키값보다 작은 경우 : 노드의 왼쪽 자식노드로 노드 a를 삽입한다.
		q->left = a;
	else									// x의 값이 노드의 키값보다 큰 경우 : 노드의 오른쪽 자식노드로 노드 a를 삽입한다.
		q->right = a;
	return;
}

void BinarySearchTree::deleteNode(NODE_TREE *node, element x)
{
	// 심화 학습 과제 : deleteNode() 함수 구현
	// 슈도 코드를 참고해 구현하세요.
	NODE_TREE *p = getRoot();						// 포인터 p를 루트 노드의 주소값으로 초기화한다. while문을 통한 탐색연산을 해야하기 때문이다.
	NODE_TREE *parent = getRoot();					// 삭제할 노드의 부모 노드를 가리키는 포인터 parent도 동일하게 초기화한다. NULL값으로 초기화할 경우 Nullptr 오류가 발생하기 때문이다.
	NODE_TREE *q = NULL;

	while (p != NULL)								// 포인터 p를 이용해 삭제할 노드를 탐색한다.
	{
		if (x == p->key)							// X 값과 노드의 키값이 같은 경우 : 원하는 노드(삭제할 노드)를 찾았으므로  break를 통해 반복문을 빠져나온다.
			break;
		if (x < p->key)								// X 값이 노드의 키값보다 작은 경우 : 노드의 왼쪽 서브트리에 대해서 탐색한다.
		{
			parent = p;
			p = p->left;
		}
		else										// X 값이 노드의 키값보다 큰 경우 : 노드의 오른쪽 서브트리에 대해서 탐색한다.
		{
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL)										// <루트노드가 없는 경우> : 삭제할 노드가 존재하지 않으니까 함수를 종료한다.
		return;
	if (p->left == NULL && p->right == NULL)			// <삭제할 노드의 차수가 0인 경우> : 노드를 삭제하고, 삭제한 노드의 부모 노드의 링크 필드에 NULL 설정한다.
	{
		if (parent->left == p)							// 부모 노드의 왼쪽 자식 노드가 p인 경우 : 부모 노드의 왼쪽 링크 필드를 NULL값으로 설정한다.
			parent->left = NULL;
		else											// 부모 노드의 오른쪽 자식 노드가 p인 경우 : 부모 노드의 오른쪽 링크 필드를 NULL값으로 설정한다.
			parent->right = NULL;
	}
	else if (p->left == NULL || p->right == NULL)		// <삭제할 노드의 차수가 1인 경우> : 삭제한 노드의 자리를 자식 노드에게 물려준다.
	{
		if (p->left != NULL)							// 삭제할 노드에 왼쪽에 서브트리가 있는 경우
		{
			if (parent->left == p)						// 삭제할 노드가 그 부모 노드의 왼쪽 자식 노드인 경우 : 부모 노드의 왼쪽 링크 필드를 삭제할 노드의 왼쪽 링크 필드 값으로 설정한다.
				parent->left = p->left;
			else										// 삭제할 노드가 그 부모 노드의 오른쪽 자식 노드인 경우	: 부모 노드의 오른쪽 링크 필드를 삭제할 노드의 왼쪽 링크 필드 값으로 설정한다.
				parent->right = p->left;
		}
		else											// 삭제할 노드의 오른쪽에 서브트리가 있는 경우
		{
			if (parent->left == p)						// 삭제할 노드가 그 부모 노드의 오른쪽 자식 노드인 경우 : 부모 노드의 왼쪽 링크 필드를 삭제할 노드의 오른쪽 링크 필드 값으로 설정한다.
				parent->left = p->right;
			else										// 삭제할 노드가 그 부모 노드의 오른쪽 자식 노드인 경우 : 부모 노드의 오른쪽 링크 필드를 삭제할 노드의 오른쪽 링크 필드 값으로 설정한다.
				parent->right = p->right;
		}
	}
	else if (p->left != NULL && p->right != NULL)		// <삭제할 노드의 차수가 2인 경우> : 삭제한 노드의 자리를 자손 노드들 중에서 선택한 후계자에게 물려줌(슈도 코드 상에서는 왼쪽 자식 노드에게 물려줌 
	{
		q = p->left;									// 노드 포인터 q에 노드 p의 왼쪽 링크 필드 값을 대입한다.
		p->key = q->key;								// p의 key값에 q의 key값을 대입한다.
		deleteNode(p->left, p->key);					// 마지막에 deleteNode 함수를 사용하므로써 삭제한 노드의 왼쪽 자식 노드가 삭제한 노드의 자리를 대체한다.
	}
}
