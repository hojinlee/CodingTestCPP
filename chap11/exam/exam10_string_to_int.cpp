#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 문자열을 정수값으로 변환
int string_to_int(string str)
{
    int ans = 0;      // 정답을 0으로 초기화
    bool neg = false; // 음수 여부 설정

    int i = 0; // 문자열 순회를 위한 인덱스 초기화
    if (str[i] == '+')
        i++;           // 양수 기호가 있으면 인덱스만 증가
    if (str[i] == '-') // 음수 기호가 있으면
    {
        i++;        // 인덱스 증가
        neg = true; // 음수로 설정
    }

    // 모든 문자를 순회
    while (i < str.size())
    {
        if (isdigit(str[i]) == false) // 숫자가 아니면 순회 중지
            break;

        int d = str[i] - '0'; // 숫자 캐릭터를 정수로 변환
        if (neg)              // 음수라면
        {
            // ans * 10 - d <이> INT_MIN인지 확인, 직접 확인하면 오버플로가 발생해서, 이항해서 계산
            if (ans < (INT_MIN + d) / 10)
                return INT_MIN; // 오버플로시 최솟값 반환
            ans = ans * 10 - d; // 이전 값의 자릿수를 올리고 현재 값을 빼기
        }
        else
        {
            // ans * 10 + d > INT_MAX인지 확인, 직접 확인하면 오버플로가 발생해서, 이항해서 계산
            if (ans > (INT_MAX - d) / 10)
                return INT_MAX; // 오버플로시 최댓값 반환
            ans = ans * 10 + d; // 이전 값의 자릿수를 올리고 현재 값을 더하기
        }

        i++; // 인덱스 증가
    }

    return ans; // 결과 반환
}

int main()
{
    cout << string_to_int("+12345") << endl;
    cout << string_to_int("12345+") << endl;

    return 0;
}
