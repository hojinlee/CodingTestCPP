#include <iostream>
#include <list>
using namespace std;

int main()
{
	// 빈 리스트 list1을 생성합니다.
	list<int> list1;

	// list1에 요소들을 추가합니다.
	list1.push_back(1); // list1: 1
	list1.push_back(3); // list1: 1 3
	list1.push_back(4); // list1: 1 3 4

	// 빈 리스트 list2를 생성합니다.
	list<int> list2;

	// list2에 요소들을 추가합니다.
	list2.push_back(5); // list2: 5
	list2.push_back(2); // list2: 5 2
	list2.push_back(6); // list2: 5 2 6

	// list1의 두 번째 요소를 가리키는 반복자의 위치에 list2의 요소들을 삽입합니다.
	// list1: 1 3 5 2 6 4, list2: empty
	list1.splice(next(list1.begin(), 2), list2);

	// list1의 요소들을 출력합니다.
	for (auto &n : list1)
		cout << n << ' '; // 1 3 5 2 6 4

	cout << endl;

	// list1과 list2의 크기를 출력합니다.
	cout << list1.size() << ", " << list2.size() << endl; // 6, 0

	return 0;
}