#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<string> words;		   // string을 원소로 갖는 list 컨테이너 생성
	words.push_front("apple"); // "apple"을 리스트의 처음에 삽입
	words.push_back("aero");   // "aero"를 리스트의 끝에 삽입
	words.push_back("good");   // "good"을 리스트의 끝에 삽입

	// 리스트의 첫 번째 원소를 가리키는 반복자 생성
	list<string>::iterator it = words.begin();

	// 반복자를 두 번이동합니다.
	for (int i = 0; i < 2; i++)
		it++; // 반복자를 다음으로 이동

	// "box"를 현재 위치(it) 앞에 삽입하고, 삽입 후에 it를 다음 위치로 이동
	words.insert(it++, "box");

	char ch = 'a';

	// 모든 원소를 출력
	for (auto &w : words)
		cout << w << ' '; // apple aero box good

	return 0;
}