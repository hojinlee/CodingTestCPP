#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<string> words; // 문자열을 저장할 리스트 생성

	// 리스트에 단어 추가
	words.push_back("apple");
	words.push_back("good");
	words.push_back("box");
	words.push_back("aero");

	// 리스트의 모든 단어 출력
	for (auto &w : words)
		cout << w << ' '; // apple good box aero
	cout << endl;

	// 단어를 알파벳순으로 정렬
	words.sort();

	// 정렬된 리스트의 모든 단어 출력
	for (auto &w : words)
		cout << w << ' '; // aero apple box good

	return 0;
}