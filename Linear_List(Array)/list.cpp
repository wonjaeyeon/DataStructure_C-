#include "List.h"
#include <iostream>


using namespace std;

// 생성자 함수
List::List()
{
    Count = 0;
}

// 소멸자 함수
List::~List() {}

// 원소 삽입 함수
void List::Insert(int Position, int Item)
{
    if (Count == MAX)
        cout << "리스트가 꽉 차 있습니다." << endl;
    else if (Position > Count + 1 || Position < 1)
        cout << "Position이 범위를 벗어났습니다." << endl;
    else
    {
        // 끝에서부터 삽입위치까지 오른쪽으로 한 칸씩 이동
        for (int i = Count - 1; i >= Position - 1; i--)
        {
            Data[i + 1] = Data[i];
        }

        // 원하는 삽입위치(Position)에 삽입
        Data[Position - 1] = Item;

        // 리스트 크기 증가
        Count++;
    }
}

void List::Delete(int Position)
{
    // 삭제 위치 확인
    if (Position < 1 || Position > Count)
        cout << "Position이 범위를 벗어났습니다." << endl;
    else
    {
        // 삭제 위치 다음에서 끝까지 왼쪽으로 한 칸씩 이동
        for (int i = Position; i < Count - 1; i++)
        {
            Data[i - 1] = Data[i];
        }

        // 리스트 크기 감소
        Count--;
    }
}


void List::Retrieve(int Position, int *ItemPtr)
{
    // 검색 위치 확인
    if (Position < 1 || Position > Count)
        cout << "Position이 범위를 벗어났습니다." << endl;
    else
        *ItemPtr = Data[Position - 1];
}

bool List::IsEmpty()
{
    return (Count == 0);
}

int List::Length()
{
    return Count;
}

void List::PrintItem()
{
    if (Count < 1)
        cout << "빈 리스트입니다." << endl;
    else
    {
        // 헤더
        cout << "위치\tData" << endl;

        // 원소 출력
        for (int i = 0; i < Count; i++)
        {
            cout << i + 1 << "\t" << Data[i] << endl;
        }

        cout << "리스트의 끝입니다." << endl;
    }
}