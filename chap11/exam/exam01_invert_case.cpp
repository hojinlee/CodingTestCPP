#include <iostream>
#include <string>

using namespace std;

void invert_case(string &str)
{
    // 문자열의 각 문자를 순회하며 대소문자를 반전
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i]; // 현재 문자
        // 대문자면 소문자로, 반대는 대문자로
        str[i] = isupper(ch) ? tolower(ch) : toupper(ch);
    }
}

int main()
{
    string str = "Apple bOx";
    invert_case(str);

    cout << str << endl;

    return 0;
}
