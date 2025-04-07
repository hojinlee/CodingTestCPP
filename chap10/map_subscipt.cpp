#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    map<int, int> sort_map; // 정렬 맵
    sort_map.emplace(3, 4);
    sort_map.emplace(3, 5);  // 키 3에 대한 값이 갱신 안됨
    sort_map.insert({3, 6}); // 키 3에 대한 값이 갱신 안됨
    cout << sort_map.at(3) << endl;

    sort_map[4] = 4;
    sort_map[4] = 5; // []을 사용하여 키 4에 대한 값이 갱신됨
    cout << sort_map.at(4) << endl;

    unordered_map<int, int> unsort_map; // 미정렬 맵
    unsort_map.emplace(3, 4);
    unsort_map.emplace(3, 5);  // 키 3에 대한 값이 갱신 안됨
    unsort_map.insert({3, 6}); // 키 3에 대한 값이 갱신 안됨
    cout << unsort_map.at(3) << endl;

    unsort_map[4] = 4;
    unsort_map[4] = 5; // []을 사용하여 키 4에 대한 값이 갱신됨
    cout << unsort_map.at(4) << endl;

    return 0;
}