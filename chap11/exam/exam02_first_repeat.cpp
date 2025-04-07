#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

char first_repeat(const string &str)
{
    // 문자열에서 발견한 문자들을 저장하는 세트
    unordered_set<char> occur;

    // 문자열의 각 문자를 순회
    for (auto &ch : str)
    {
        // 셋에 이미 존재하는 문자라면
        if (occur.find(ch) != occur.end())
            return ch;    // 중복을 의미하므로 반환
        occur.insert(ch); // 셋에 현재 문자 삽입
    }

    return ' '; // 반복 문자가 없을 때  공백을 반환
}

int main()
{
    cout << first_repeat("aeroplane") << endl;
    cout << first_repeat("abc!de!") << endl;

    return 0;
}
