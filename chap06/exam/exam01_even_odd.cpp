#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void even_odd(const vector<int> &nums)
{
    deque<int> dq; // 양방향으로 데이터를 넣을 수 있는 덱을 사용

    for (int n : nums)
    {
        if (n & 1) // 홀수
        {
            dq.push_back(n); // 뒤로 넣어서 순서 유지
        }
        else // 짝수
        {                     
            dq.push_front(n); // 앞으로 넣어서 순서 뒤집힘
        }
    }

    for (int n : dq)
        cout << n << " "; // 덱의 원소를 차례대로 출력
    cout << endl;
}

int main()
{
    even_odd({7, 2, 5, 4, 3});
    return 0;
}