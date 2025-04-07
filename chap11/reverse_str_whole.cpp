#include <iostream>

using namespace std;

// 문자열 전체 뒤집기
void reverse_str(string &str)
{
    const int len = str.size();
    const int half = len / 2; // 문자열의 길이 절반

    // 문자열의 앞 절반을 순회
    for (int i = 0; i < half; i++)
    {
        // 문자열의 뒷 절반과 교환
        swap(str[i], str[len - 1 - i]);
    }
}

int main()
{
    string str = "TEXT APPLE BOX";
    // 변환 전 문자열 출력
    cout << str << endl; // "TEXT APPLE BOX"
    reverse_str(str);
    // 변환 후 문자열 출력
    cout << str << endl; // "XOB ELPPA TXET"

    return 0;
}