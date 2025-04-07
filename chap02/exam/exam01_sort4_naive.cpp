// sort array which includes '0, 1, 2, 3' only
// O(n log n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_0123(vector<int>& data) 
{
    sort(data.begin(), data.end());
}

int main() 
{
    vector<int> data = { 0, 1, 3, 2, 3, 2, 1, 0, 1};
    sort_0123(data);
    for(int i: data)
        cout << i << ", " ; // 0, 0, 1, 1, 1, 2, 2, 3, 3, 
    cout << endl;
    return 0;
}
