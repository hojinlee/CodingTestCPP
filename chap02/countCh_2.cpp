#include <iostream>
#include <string>

using namespace std;

void countCh(const string& str)
{
    int mapChar[26] = {0,}; // 알파벳에 대한 카운트를 저장
    for(auto& i : str) // 문자열 str의 각 문자 i에 대해 반복
    {
        mapChar[i - 'a']++; // 알파벳에 해당하는 값을 증가
    }
    
    for(int i=0; i<26; i++) // a부터 z까지 순회
    {
        if( mapChar[i] >0 )
        {
            cout << char('a' + i)  << ":" << mapChar[i] << " " ; // 키-값을 출력
        }
        
    }
}

int main() {
    
    countCh("helloworld"); //d:1 e:1 h:1 l:3 o:2 r:1 w:1 
    return 0;
}