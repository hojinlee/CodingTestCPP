#include <iostream>
#include <list>
using namespace std;

int main()
{
	// 첫 번째 리스트 생성
	list<int> list1;

	// 첫 번째 리스트에 요소 추가
	list1.push_back(1);
	list1.push_back(3);
	list1.push_back(4);

	// 두 번째 리스트 생성
	list<int> list2;

	// 두 번째 리스트에 요소 추가
	list2.push_back(5);
	list2.push_back(2);
	list2.push_back(6);

	// 리스트들을 정렬합니다.
	list1.sort();
	list2.sort();

	// 두 리스트를 병합합니다.
	list1.merge(list2);

	// 병합된 리스트의 요소들을 출력합니다.
	for (auto &n : list1)
		cout << n << ' '; // 1 2 3 4 5 6

	return 0;
}