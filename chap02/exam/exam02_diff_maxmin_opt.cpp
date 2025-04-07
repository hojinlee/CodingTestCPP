// O(n)
#include <iostream>
#include <vector>
#include <limits.h> 
using namespace std;

int diff_maxmin(vector<int>& data) 
{
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    
    for(int i: data)
    {
        min_value = min(min_value, i);
        max_value = max(max_value, i);
    }

    return max_value - min_value;
}

int main() 
{
    vector<int> data = { 1, 4, 5, 3, 2};
    cout << diff_maxmin(data) << endl; // 4
    return 0;
}
