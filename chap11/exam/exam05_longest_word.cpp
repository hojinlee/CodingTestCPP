#include <iostream>
#include <string>

using namespace std;

// str에서 가장 긴 단어의 길이를 반환
int longest_word(const string &str)
{
    int ans = 0; // 가장 긴 단어의 길이를 저장
    int cur = 0; // 현재 단어의 길이를 저장

    // 문자열의 모든 단어를 순회
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i]; // 현재 문자

        if (isalpha(ch)) // 현재 문자가 알파벳이 아니면
        {
            cur++; // 현재 단어의 길이를 증가
        }
        else // 알파벳이 아니면
        {
            ans = max(ans, cur); // 정답을 갱신
            cur = 0;             // 현재 단어의 길이를 초기화
        }
    }

    ans = max(ans, cur);

    return ans;
}

int main()
{
    cout << longest_word("Hello, good morning!") << endl;

    return 0;
}
