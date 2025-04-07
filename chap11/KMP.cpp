#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(const string &text)
{
    int n = text.length(); // 문자열의 전체 길이
    // 접두사 와 접미사가 일치하는 최대 길이를 저장하는 배열
    vector<int> pi(n);

    for (int i = 1, j = 0; i < n; i++) // text[0]과 text[0]은 비교하지 않으니, n-1개만 순회
    {
        while (j > 0 && text[i] != text[j]) // 접두사 및 접미사가 일치하지 않을 때
            j = pi[j - 1];                  // 일치하지 않는 경우, 이전 인덱스에서 저장된 접두사 및 접미사 길이를 사용하여 다음 비교 위치로 이동

        if (text[i] == text[j]) // 접두사 및 접미사가 일치할 때
            pi[i] = ++j;        // 현재 위치의 접두사 및 접미사 길이 갱신 후, 다음 위치로 이동
    }

    return pi; // 접두사 및 접미사 길이 배열 반환
}

// text: 탐색할 전체 문자열, target: text에서 찾으려는 대상 문자열 패턴
int KMP(const string &text, const string &target)
{
    int n = text.length(); // 전체 문자열의 길이
    int m = target.length();
    // 대상 패턴보다 문자열의 길이가 짧을 땐 매칭을 중단하고 -1을 반환
    if (n < m)
        return -1;

    // 타깃 패턴의 pi 변수를 구해서 벡터로 저장
    vector<int> pi(get_pi(target)); 

    // i는 대상 문자열 순회에, j는 패턴 순회에 사용
    for (int i = 0, j = 0; i < n; i++)
    {
        // 이전에 비교한 값 중 일치하는 가장 긴 길이를 구해서
        while (j > 0 && text[i] != target[j])
            j = pi[j - 1]; // 그 부분을 스킵하고 비교합니다.

        if (text[i] == target[j]) // 비교 지점의 문자가 일치하면
        {
            // j 루프의 모든 문자가 일치, 타깃 패턴을 찾음
            if (j == m - 1)
                // 문자열이 일치하는 시작 인덱스를 반환
                return i - m + 1;

            j++; // 패턴의 다음 문자를 비교
        }
    }

    // 타깃 패턴과 일치하는 것이 없으면 -1을 반환
    return -1;
}

int main()
{
    cout << KMP("xyxxyxyxyz", "xyxyz") << endl;
    cout << KMP("xxxyxyxyz", "xxxyz") << endl;

    return 0;
}