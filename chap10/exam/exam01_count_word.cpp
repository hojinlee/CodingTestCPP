#include <iostream>
#include <map>
using namespace std;

void count_word(string text)
{
    int start = 0;
    map<string, int> cnt_map; // 단어의 수를 세어 저장하는 빈도 맵

    // 문장의 마지막에 공백을 더해 for 문이 끝난 뒤에도 따로 처리하지 않도록 합니다.
    text += " ";

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ') // 공백을 만나면
        {
            cnt_map[text.substr(start, i - start)]++; // 토큰을 구하여 빈도 맵 갱신
            start = i + 1;                            // 다음 인덱스를 시작점으로 변경
        }
    }

    for (auto &w : cnt_map) // 빈도 맵에서 각 단어와 그 빈도를 출력
    {
        cout << w.first << ": " << w.second << endl;
    }
}

int main()
{
    count_word("apple box book apple book");

    return 0;
}
