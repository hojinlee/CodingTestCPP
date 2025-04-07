#include <iostream>
#include <algorithm>

using namespace std;

// 애너그램 여부를 확인하는 함수
bool is_anagram(string str1, string str2)
{
    // 두 문자열을 소문자로 변환합니다.
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // 알파벳 갯수 만큼 카운터를 생성
    int counter[26] = {
        0,
    };

    // 첫 번째 문자열을 읽어 카운터 배열에 더합니다.
    for (auto ch : str1)
    {
        if (isalpha(ch)) // 알파벳만 처리
        {
            counter[ch - 'a']++; // 카운터 증가
        }
    }

    // 두 번째 문자열을 읽어 카운터 배열에서 뺍니다.
    for (auto ch : str2)
    {
        if (isalpha(ch)) // 알파벳만 처리
        {
            counter[ch - 'a']--; // 카운터 감소
        }
    }

    // 카운터 배열을 순회
    for (int i = 0; i < 26; i++)
    {
        // 하나라도 0이 아니면
        if (counter[i] != 0)
            return false; // 애너그램이 아닙니다.
    }

    return true; // 애너그램입니다.
}

int main()
{
    cout << is_anagram("Elvis", "Lives") << endl;                               // 1
    cout << is_anagram("Gone with the wind", "Then weigh it down") << endl;     // 1
    cout << is_anagram("The towering inferno", "No worth fire engine") << endl; // 0

    return 0;
}