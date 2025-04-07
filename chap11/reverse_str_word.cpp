#include <iostream>

using namespace std;

// [start, end) 사이의 문자열을 뒤바꾸는 함수
void reverse_str(string &str, int start, int end)
{
    const int len = end - start; // 처리할 구간의 길이
    const int half = len / 2;    // 절반의 구간만 순회하기 위해 절반 길이 구하기

    // 문자열의 앞 절반을 순회
    for (int i = 0; i < half; i++)
    {
        // 문자열의 뒷 절반과 교환
        swap(str[i + start], str[end - 1 - i]);
    }
}

// 단어 단위로 위치를 뒤바꾸는 함수
void reverse_word(string &str)
{
    // 문자열 전체를 뒤집기
    reverse_str(str, 0, str.size());

    int start = 0; // 단어의 시작점
    int i = 0;     // for 문 밖에서 i를 사용하기 위해 여기서 선언
    for (; i < str.size(); i++)
    {
        if (str[i] == ' ') // 공백을 발견하면
        {
            reverse_str(str, start, i); // 단어 뒤집기
            start = i + 1;              // 다음 단어의 시작점 갱신
        }
    }
    reverse_str(str, start, i); // 문장의 끝에서 마지막 단어 뒤집기
}

int main()
{
    string str = "TEXT APPLE BOX";
    // 변환 전 문자열 출력
    cout << str << endl;
    reverse_word(str);
    // 변환 후 문자열 출력
    cout << str << endl;

    return 0;
}