#include <iostream>
#include <list>
using namespace std;

list<int> mul_list(list<int> n, list<int> m)
{
    list<int> ans;
    int len_ans = n.size() + m.size(); // n과 m의 곱은 각 길이의 합보다 길지 않음
    for (int i = 0; i < len_ans; i++)
    {
        ans.push_front(0); // 값을 저장할 공간을 확보
    }

    int pos1(0), pos2(0);
    auto ans_ptr1 = ans.rbegin();
    auto ans_ptr2 = ans_ptr1;
    for (auto rit1 = n.rbegin(); rit1 != n.rend(); rit1++, pos1++) // rit: reverse iterator
    {
        int carry(0), i(pos2);

        // 직전에 사용한 노드의 다음 노드를 사용
        ans_ptr2 = ans_ptr1;
        for (auto rit2 = m.rbegin(); rit2 != m.rend(); rit2++, i++)
        {
            // rit1과 rit2는 iterator라 *를 붙여야 값으로 사용
            int prod = *rit1 * *rit2 + carry;
            *ans_ptr2 += prod % 10; // 결과 노드에 값 더하기

            // 1자리 이상 결과에 대해 처리하기
            carry = prod / 10 + *ans_ptr2 / 10;
            *ans_ptr2 = *ans_ptr2 % 10;

            ans_ptr2++; // 다음 접근자로
        }

        if (carry) // 자리 올림수가 남았다면
            *ans_ptr2 = carry;

        ans_ptr1++;
    }

    // 앞쪽에 위치한 0노드를 제거
    while (ans.front() == 0)
        ans.pop_front();

    return ans;
}

int main()
{
    list<int> ans = mul_list({7, 4, 2}, {4, 3, 2});

    for (auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}