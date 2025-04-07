#include <iostream>
#include <vector>
#include <set>

using namespace std;

void remove_redundant_sort(vector<int> &in, vector<int> &out)
{
    set<int> s;
    for (auto &i : in)
        s.emplace(i); // 세트에 값을 삽입하여 중복을 제거합니다.

    for (auto &i : s)
        out.emplace_back(i); // 세트의 원소를 벡터에 삽입합니다.
}

int main()
{
    vector<int> datas = {5, 4, 5, 1, 2};
    vector<int> result;
    remove_redundant_sort(datas, result);

    for (auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}