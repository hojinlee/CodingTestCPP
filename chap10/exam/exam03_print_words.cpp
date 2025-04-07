#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 특정 문자로 시작하는 단어를 중복없이 출력
void print_words(const vector<string> &words, char start)
{
    set<string> ans; // 중복없이 정렬하기 위해 set을 사용

    // 벡터의 모든 문자열 순회
    for (auto &word : words)
    {
        if (word[0] == start) // 문자열의 첫 번째 문자가 start이면
        {
            ans.insert(word); // 해당 문자를 결괏값에 추가
        }
    }

    for (auto it : ans)
    {
        // 결과 출력
        cout << it << " ";
    }
}

int main()
{
    print_words({"apple", "box", "apple", "aero"}, 'a');

    return 0;
}
