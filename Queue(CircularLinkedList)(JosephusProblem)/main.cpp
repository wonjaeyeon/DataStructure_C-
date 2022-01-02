#include <iostream>
#include "QueueByCircularLinkedList.h"

using namespace std;

int main()
{
    const int N = 41;
    const int M = 3;

    QueueByCircularLinkedList Q;

    // 요세푸스(Josephus)의 문제를 해결하기 위한 로직을 코딩하세요.
    // 반드시 Q를 사용해야하고
    // N과 M의 숫자가 바뀌어도 동작하는 로직으로 코딩하세요.
    for (int i = 1; i <= N; i++)
    {
        Q.enQueue(i);   // 원형 연결 리스트 큐에 1부터 41까지 숫자를 삽입한다. 숫자는 사람들이 앉은 각 자리의 번호를 의미한다.
    }
    int j = 1;                          // 변수 j를 1로 초기화하여 첫번째 사람부터 차례대로 요세푸스 문제에 맞게 처리한다. 
    while (Q.GetSize() >= M)            // (N-1)명이 생존할 때까지 다음 시행을 계속 반복한다.
    {
        if (j % M != 0)                 // 다음 N번째 사람마다 제거하므로 현재 순서의 사람이 다음 N번째 사람인지 파악한다.
        {
            Q.enQueue(Q.GetFront());    // 현재 검사중인 사람이 다음 N번째 사람이 아니라면 enQueue와 deQueue를 이용하여 원형 큐 Q의 Front 값을 뒤로 이동시킨다.
            Q.deQueue();                
        }
        else
        {
            Q.deQueue();                // 현재 검사중인 사람이 다음 N번째 사람이라면 큐의 Front 값을 삭제한다.
        }
        j++;                            // j를 1씩 더하여 다음 차례의 사람으로 넘어간다.
    }                                   // while 반복문을 마치면 Q 안에는 마지막 생존자가 앉은 자리 번호 2개가 남게 된다.
    cout << "마지막 생존자가 앉은 자리의 번호는 ";
    while (!Q.IsEmpty())
    {
        cout << Q.deQueue();

        if (!Q.IsEmpty())
            cout << ", ";
    }
    cout << " 입니다.";

    return 0;
}
