#include <iostream>
#include <math.h>

using namespace std;

// 라빈 카프 문자 탐색, text: 탐색할 입력 문자열, target: 찾으려는 패턴 문자열
int RabinKarp_match(const string &text, const string &target)
{
    int n = text.length();   // 문자열의 길이를 n에 저장
    int m = target.length(); // 패턴 패턴의 길이를 m에 저장
    // 문자열의 길이가 패턴 패턴의 길이보다 짧을 경우, 매칭을 중단하고 -1을 반환
    if (n < m)
        return -1;

    // HashText: text 문자열의 해시값을 저장하는 변수
    // HashTarget: target 문자열의 해시값을 저장하는 변수
    unsigned int HashText = 0, HashTarget = 0;

    // 패턴 패턴의 길이만큼 순회
    for (int i = 0; i < m; i++)
    {
        HashText += text[i] * pow(2, i);     // 자릿수만큼 2를 곱해 줌
        HashTarget += target[i] * pow(2, i); // 자릿수만큼 2를 곱해 줌
    }

    // 이 반복문 내부에서 m만큼 이동하기 때문에 여기서는 m크기를 제외하고 이동
    for (int i = 0; i <= n - m; i++)
    {
        if (i > 0) // 비교할 문자열의 해쉬를 새로 계산
        {
            HashText -= text[i - 1]; // 직전 해시값에서 첫 번째 문자에 대한 값을 제거
            HashText /= 2;           // 왼쪽으로 한 칸 이동
            // i + m - 1 : 비교할 문자열의 마지막 문자 인덱스, m - 1: 패턴의 마지막 문자 위치
            HashText += text[i + m - 1] * pow(2, m - 1); // 마지막에 더할 문자를 m - 1 만큼 이동
        }

        // 해시 값이 같을 때는 패턴 전체를 비교
        if (HashText == HashTarget)
        {
            int j = 0;         // for 반복문 밖에서 j를 비교하려고 여기서 선언
            for (; j < m; j++) // m 크기만큼 순회
            {
                if (text[i + j] != target[j]) // 해시값을 비교하며 하나라도 다르면
                    break;                    // j 루프 중단
            }

            // j 루프의 모든 문자가 일치, 타겟 패턴을 찾으면
            if (j == m)
                return i; // 패턴 패턴의 시작 위치 i를 정답으로 반환
        }
    }

    // 타겟 패턴과 일치하는 것이 없으면 -1을 반환
    return -1;
}

int main()
{
    string text = "aappaapplea";
    string target = "apple";
    cout << RabinKarp_match(text, target) << endl;
    return 0;
}