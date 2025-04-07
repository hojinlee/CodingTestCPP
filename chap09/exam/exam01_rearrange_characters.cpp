#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string rearrange_characters(const string &str)
{
    const int n = str.length();

    // 각 문자의 빈도를 저장할 배열, 알파벳의 갯수만큼 크기를 잡음
    int count[26] = {0};

    // 각 문자의 빈도 계산
    for (int i = 0; i < n; i++)
    {
        count[str[i] - 'a']++;
    }

    // 빈도와 문자를 저장하는 우선순위 큐
    priority_queue<pair<int, char>> pq;

    // 각 문자와 그 빈도를 우선순위 큐에 추가
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (count[c - 'a'])
        {
            // if (count[c - 'a'] > half)
            //     return "-";

            pq.push(make_pair(count[c - 'a'], c));
        }
    }

    // 결과를 저장할 문자열 초기화
    string ans = "";

    // 이전에 처리한 문자를 저장할 변수
    pair<int, char> prev = make_pair(-1, '#'); // 처음엔 이전 문자가 없기 때문에 -1 빈도를 가지는 문자를 삽입

    // 모든 문자를 처리
    while (!pq.empty())
    {
        pair<int, char> cur = pq.top(); // 가장 빈도가 높은 문자를 가져옴
        pq.pop();                       // 현재 처리하는 문자를 큐에서 제거해서 중복되지 않게 함

        // 결과 문자열에 현재 문자를 추가
        ans = ans + cur.second;

        if (prev.first > 0) // 이전 문자의 빈도가 남아 있다면
        {
            pq.push(prev); // 다시 큐에 추가
        }

        (cur.first)--; // 빈도를 감소시키고
        prev = cur;    // 이전 문자를 업데이트
    }

    // 입력 문자열이 중복 조건을 만족할 수 없는 경우에 ans의 길이가 n보다 짧습니다.
    if (n != ans.length())
        ans = "-";

    return ans;
}

int main()
{
    cout << rearrange_characters("bbcdc") << endl;
    cout << rearrange_characters("bbbbc") << endl;

    return 0;
}
