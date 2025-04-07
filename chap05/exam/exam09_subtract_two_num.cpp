#include <iostream>
#include <list>
using namespace std;

list<int> subtract_list(list<int> n, list<int> m)
{
    list<int> ans;

    int borrow(0); // 빌린 수
    while(!n.empty() || !m.empty())
    {
        int n1(0), m1(0); 
        if(!n.empty())
        {
            n1 = n.back(); // 마지막 노드의 값을 더한다
            n.pop_back(); // 더한 노드는 리스트에서 제거
        }
        if(!m.empty())
        {
            m1 = m.back(); // 마지막 노드의 값을 더한다
            m.pop_back(); // 더한 노드는 리스트에서 제거
        }
        int diff = n1 - m1 - borrow; 
        if(diff < 0) // 뺄셈 결과가 음수면, 윗자리에서 숫자를 빌려옴
        {
            borrow = 1; // 빌려온 값 설정
            diff += 10; // 빌려온 값을 더하기
        }
        else
        {
            borrow = 0;
        }
        ans.push_front(diff); 
    }

    // 0001 같이 앞에 0이 있다면 제거, n > m이라는 전제 조건에 따라 0000은 고려하지 않아도 됨
    while(!ans.empty() && ans.front() == 0)
    {
        ans.pop_front();
    }

    return ans; 
}

int main()
{
    list<int> ans = subtract_list({7, 3, 2}, {4, 4, 2});

    for(auto i: ans)
        cout << i << ' ';
    cout << endl; 
    
    return 0;
}