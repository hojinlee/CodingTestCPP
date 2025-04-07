#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<char, int> map1;

    map1.emplace('c', 1);
    map1.emplace('z', 4);

    auto it = map1.begin();
    map1.emplace_hint(it, 'a', 0);
    // lower_bound는 b보다 큰 값 중에 가장 작은 값을 찾음
    it = map1.lower_bound('b');
    cout << "lower: " << it->first << ", " << it->second << endl;

    it = map1.erase(it);
    cout << "after erase: " << it->first << ", " << it->second << endl;

    it = map1.emplace_hint(it, 'd', 5); // 잘못된 hint로 z를 가리킴. O(logn)시간에 수행
    cout << "after emplace: " << it->first << ", " << it->second << endl;

    it = map1.emplace_hint(it, 'e', 6); // 정상 hint. O(1)
    cout << "after emplace: " << it->first << ", " << it->second << endl;

    cout << "----" << endl;
    for (auto item : map1)
    {
        cout << item.first << ", " << item.second << endl;
    }

    return 0;
}