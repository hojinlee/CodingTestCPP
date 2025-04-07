#include <iostream>
#include <unordered_map>
using namespace std;

// 로마 숫자를 정수로 변환
int roman_to_int(const string &roman)
{
    int ans = 0;
    // 로마 숫자에 대응하는 정숫값을 정의
    std::unordered_map<char, int> map_roman =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

    int prev = 0;

    // 낮은 자리의 값부터 변환해 줍니다.
    for (int i = roman.length() - 1; i >= 0; i--)
    {
        int cur = map_roman[roman[i]];

        if (cur < prev) // 현재값이 이전보다 작다면, IX나 IV같은 경우
            ans -= cur; // 현재값을 총합에서 뺀다
        else
            ans += cur; // 현재값에 더해준다
        prev = cur;
    }
    return ans;
}

int main()
{
    cout << roman_to_int("MMXXIII") << endl;

    return 0;
}
