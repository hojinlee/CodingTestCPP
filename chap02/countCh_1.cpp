#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void countCh(const string &str)
{
    unordered_map<char, int> mapChar;
    for (auto &i : str) // 문자열 str의 각 문자 i에 대해 반복
    {
        mapChar[i]++; // 문자 i에 해당하는 인덱스에 카운트 증가
    }

    for (auto &it : mapChar) // it는 mapChar에 대한 iterator
    {
        cout << it.first << ":" << it.second << " "; // 키-값을 출력
    }
}

int main()
{

    countCh("helloworld"); // d:1 e:1 h:1 l:3 o:2 r:1 w:1
    return 0;
}