#include <iostream>
#include <vector>

using namespace std;

int count_pairs_sum(const vector<int>& arr, int targetSum) 
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = i + 1; j < arr.size(); j++) 
        {
            if (arr[i] + arr[j] == targetSum) 
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << count_pairs_sum(arr, 7) << endl;
    return 0;
}
