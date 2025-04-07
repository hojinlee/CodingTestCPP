#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_unique_elements(const vector<int>& arr)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int uniqueCount = 0;
    for (int i = 0; i < sortedArr.size(); i++) 
    {
        if (i == 0 || sortedArr[i] != sortedArr[i - 1]) 
        {
            uniqueCount++;
        }
    }
    return uniqueCount;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 5};
    cout << count_unique_elements(arr) << endl;
    return 0;
}
