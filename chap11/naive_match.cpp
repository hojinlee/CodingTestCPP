#include <iostream>

using namespace std;

// 나이브 알고리즘으로 문자 탐색, text: 탐색할 입력 문자열, target: 찾으려는 패턴 문자열
int naive_match(const string &text, const string &target)
{
    int n = text.length();   // 문자열의 길이를 n에 저장
    int m = target.length(); // 패턴 패턴의 길이를 m에 저장
    // 문자열의 길이가 패턴 패턴의 길이보다 짧을 경우, 매칭을 중단하고 -1을 반환
    if (n < m)
        return -1;

    // i를 0부터 n - m + 1까지 반복
    for (int i = 0; i <= n - m + 1; i++)
    {
        int j = 0;
        for (; j < m; j++) // j를 0부터 m까지 반복
        {
            // 현재 위치의 문자가 패턴 패턴의 문자와 다를 경우
            if (text[i + j] != target[j])
                break; // 중단
        }

        // j 루프의 모든 문자가 일치, 타겟 패턴을 찾으면
        if (j == m)
            return i; // 패턴 패턴의 시작 위치 i를 정답으로 반환
    }

    // 패턴 패턴을 찾지 못한 경우 -1 반환
    return -1;
}

int main()
{
    string text = "aappaapplea"; // 텍스트 문자열 정의
    string target = "apple";     // 타겟 패턴 정의
    cout << naive_match(text, target) << endl;

    return 0;
}