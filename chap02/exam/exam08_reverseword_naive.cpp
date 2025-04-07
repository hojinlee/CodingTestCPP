// 공간 복잡도 O(n)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
void reverse_word(string& str)
{
    vector<string> buf;
    int start = 0, end  = str.size();
    for(int i = 0; i < str.size(); i++)
    {
        // 단어를 찾습니다.
        if(str[i] == ' ')
        {
            end = i;
            // 단어를 별도의 벡터에 추가합니다.
            buf.push_back(str.substr(start, end - start));
            start = end + 1;
        }
    }
    
    buf.push_back(str.substr(start, str.size() - start));

    str = "";
    // 벡터의 뒤에서 부터 단어를 꺼내 결과 문자열에 추가합니다.
    for(int i = buf.size() - 1; i > 0; i--)
    {
        str += buf[i];
        str += " ";
    }
    str += buf[0];
}
 
int main() 
{
    string str = "apple plane box"; 
    reverse_word(str);
    cout << str << endl; // box plane apple
    return 0;
}