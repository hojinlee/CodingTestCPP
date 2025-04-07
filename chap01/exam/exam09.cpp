#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr, int target)
{
    int mid;
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(target < arr[mid]) 
            high = mid - 1;
        else if(target > arr[mid]) 
            low = mid + 1;
        else break;
    }
    return mid;
}

int main()
{
    vector<int> data = { 1,2,3,4,6,8,9 };
    binary_search(data, 4);

    return 0;
}
