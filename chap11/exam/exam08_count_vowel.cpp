#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// 문자열에서 모음의 개수를 반환
int count_vowel(const string &str)
{
    int count = 0; // 결과 저장할 변수를 0으로 초기화
    // 모음의 목록을 미정렬 세트로 저장
    unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});

    // 문자열의 모든 단어를 순회
    for (char ch : str)
    {
        ch = tolower(ch);                  // 소문자로 변환
        if (vowel.find(ch) != vowel.end()) // 현재 문자가 모음 세트에 있다면
            count++;                       // 개수를 증가
    }

    return count; // 결과 개수를 반환
}

int main()
{
    cout << count_vowel("hello world") << endl;

    return 0;
}
