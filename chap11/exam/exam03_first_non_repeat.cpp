#include <iostream>
#include <string>

using namespace std;

char first_non_repeat(const string &str)
{
    // 알파벳 크기의 해시 맵을 사용하여 문자의 출현 횟수를 저장
    int cnt_map[26] = {
        0,
    };

    // 문자열의 각 문자를 순회
    for (auto &ch : str)
    {
        cnt_map[ch - 'a']++; // 현재 문자의 개수를 증가
    }

    // 문자열의 각 문자를 다시 순회
    for (auto &ch : str)
    {
        if (cnt_map[ch - 'a'] == 1) // 중복 없는 문자를 발견하면
            return ch;              // 현재 문자를 반환
    }

    return '!'; // 반복 문자가 없을 때 !를 반환
}

int main()
{
    cout << first_non_repeat("blueblade") << endl;
    cout << first_non_repeat("blueblue") << endl;

    return 0;
}
