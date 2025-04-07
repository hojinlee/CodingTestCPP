#include <iostream>
#include <string>

using namespace std;

// str의 각 단어의 첫 글자를 대문자로 바꿔서 출력
void capitalize_first_letter(string &str)
{
    bool new_word = true; // 새로운 단어의 시작인지

    // 문자열의 모든 단어를 순회
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i]; // 현재 문자

        if (new_word && isalpha(ch)) // 단어의 시작이고 알파벳이면
        {
            str[i] = toupper(ch); // 대문자로 변경
            new_word = false;     // 새 단어가 아니라고 설정
        }
        else if (ch == ' ') // 현재 문자가 공백이면
        {
            new_word = true; // 새로운 단어의 시작으로 설정
        }
    }
}

int main()
{
    string str("happy day");
    capitalize_first_letter(str);
    cout << str << endl;

    return 0;
}
