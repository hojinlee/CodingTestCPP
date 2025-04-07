#include <iostream>
#include <list>
using namespace std;

/*
각 리스트의 맨 뒤로 이동
각 수를 더해서 carry 와 value를 구함
리스트의 헤드에 삽입
*/ 

list<int> add_list(list<int> n, list<int> m)
{
    list<int> ans;

    int carry(0); // 자리 올림 수
    while(!n.empty() || !m.empty())
    {
        int sum(carry); // 이전 연산에서 구한 자리 올림수로 초기화
        if(!n.empty())
        {
            sum += n.back(); // 마지막 노드의 값을 더한다
            n.pop_back(); // 더한 노드는 리스트에서 제거
        }
        if(!m.empty())
        {
            sum += m.back(); // 마지막 노드의 값을 더한다
            m.pop_back(); // 더한 노드는 리스트에서 제거
        }
        carry = sum / 10; // 합의 자리 올림 구하기
        sum %= 10; // 합은 10 이상만 사용

        // 낮은 자리수부터 삽입하므로 앞에 삽입해야, 뒤에 삽입하는 높은 자릿수가 앞쪽으로
        ans.push_front(sum); 
    }
    if(carry > 0) // 자리 올림수가 남았다면
        ans.push_front(carry);

    return ans; 
}

int main()
{
    list<int> ans = add_list({7, 4, 2}, {4, 3, 2});

    for(auto i: ans)
        cout << i << ' ';
    cout << endl; 
    
    return 0;
}