#include <iostream>
#include <stack>
using namespace std;

// 십진수를 2진수 문자열로 변환
string decimal_to_binary(int decimal)
{
    string ans;

    // 나머지값을 구해서 역순으로 만들기 위해 스택을 사용
    stack<int> binary_stack;

    while (decimal != 0) // 십진수가 0으로 사라질 때 까지 반복
    {
        int remainder = decimal % 2;  // 2로 나눈 나머지 값을 구함
        binary_stack.push(remainder); // 나머지값을 스택에 넣기
        decimal = decimal / 2;        // 십진수를 2로 나눔
    }

    while (!binary_stack.empty()) // 2진수 스택이 빌때까지
    {
        ans += to_string(binary_stack.top()); // 꼭대기 값을 꺼내서 정답 문자열에 붙이기
        binary_stack.pop();
    }

    return ans;
}

int main()
{
    cout << decimal_to_binary(8) << endl;
    cout << decimal_to_binary(122001) << endl;
    return 0;
}
