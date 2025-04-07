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

	// remove_if()를 이용하여 조건에 맞는 원소 제거
	words.remove_if([](const string &word)
					{ return word.find('a') != string::npos; });

	return 0;
}