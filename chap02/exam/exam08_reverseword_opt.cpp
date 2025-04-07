// 공간 복잡도 O(1)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
void reverse_word(string& str)
{
    // 전체 문자열을 뒤집습니다.
    reverse(str.begin(), str.end()); // xob enalp elppa
    int start = 0, end  = str.size();
    for(int i = 0; i < str.size(); i++)
    {
        // 단어를 찾습니다.
        if(str[i] == ' ')
        {
            end = i;
            // 각 단어를 뒤집습니다. xob -> box, enalp -> plane
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    
    // 공백으로 구별하고 남은 마지막 단어를 뒤집습니다. elppa -> apple
    reverse(str.begin() + start, str.end());
    
}
 
int main() 
{
    string str = "apple plane box"; // box plane apple
    reverse_word(str);
    cout << str << endl; 
    return 0;
}