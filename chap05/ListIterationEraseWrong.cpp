#include <iostream>
#include <list>
using namespace std;

int main()
{
	// list 컨테이너를 생성하고 원소들을 추가합니다.
	list<string> words;
	words.push_back("apple");
	words.push_back("box");
	words.push_back("aero");
	words.push_back("good");

	// 삭제할 문자
	char ch = 'a';

	// 잘못된 코드
	for (auto it = words.begin(); it != words.end(); it++)
	{
		// 현재 원소를 검사하여 문자가 포함되어 있는지 확인합니다.
		if ((*it).find(ch) != string::npos)
		{
			// 문자가 포함되어 있으면 현재 원소를 삭제합니다.
			words.erase(it);
		}
	}

	return 0;
}
