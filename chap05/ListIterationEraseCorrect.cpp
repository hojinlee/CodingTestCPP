#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<string> words;
	words.push_back("apple");
	words.push_back("box");
	words.push_back("aero");
	words.push_back("good");

	char ch = 'a';

	// 요소 추가
	words.push_back("add");
	words.push_back("another");

	// 정상 코드
	for (auto it = words.begin(); it != words.end();)
	{
		if ((*it).find(ch) != string::npos)
		{
			it = words.erase(it); // 문자를 포함한 원소를 삭제하고 다음 원소로 이동
		}
		else // 삭제 동작을 하지 않을 때만 반복자를 증가시킴
		{
			it++;
		}
	}

	// 리스트 출력
	for (const auto &word : words)
	{
		cout << word << " ";
	}
	cout << endl;

	return 0;
}