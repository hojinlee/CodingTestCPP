#include <iostream>
#include <stack>

using namespace std;

void reverse_word_stack(string &str)
{
    stack<string> stk;

    string buf(""); // 한 단어를 저장하기 위한 버퍼
    for (int i = 0; i < str.size(); i++)
    {
        // 공백이 아니면 버퍼에 추가하여 단어를 만들어 가기
        if (str[i] != ' ')
            buf += str[i];
        else // 공백을 만나면
        {
            // 현재까지 버퍼에 저장한 단어를 스택에 삽입하고 버퍼를 초기화
            stk.push(buf);
            buf = "";
        }
    }

    // 스택에서 단어를 꺼내며 버퍼에 추가
    while (!stk.empty())
    {
        buf += " ";
        buf += stk.top();
        stk.pop();
    }

    str = buf; // 반전된 단어를 저장한 버퍼를 결과 문자열로
}

int main()
{
    string str = "TEXT APPLE BOX";
    // 변환 전 문자열 출력
    cout << str << endl; // "TEXT APPLE BOX"
    reverse_word_stack(str);
    // 변환 후 문자열 출력
    cout << str << endl; // "BOX APPLE TEXT"

    return 0;
}