#include <iostream>
#include <string>

using namespace std;

// str: 찾으려는 문자열, k: k번째 유일한 문자
char kth_non_repeat(const string &str, int k)
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

    int cnt = 0; // 유일한 문자의 개수를 저장
    // 문자열의 각 문자를 다시 순회
    for (auto &ch : str)
    {
        if (cnt_map[ch - 'a'] == 1) // 중복 없는 문자를 발견하면
        {
            cnt++;         // 카운터 증가
            if (cnt == k)  // k번째 유일한 문자라면
                return ch; // 현재 문자를 반환
        }
    }

    return '!'; // 반복 문자가 없을 때 !를 반환
}

int main()
{
    cout << kth_non_repeat("blueblade", 3) << endl;
    cout << kth_non_repeat("blueblue", 3) << endl;

    return 0;
}
