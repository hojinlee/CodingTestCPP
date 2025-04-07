#include <vector>
#include <iostream>

using namespace std;

int count_odd_numbers(const std::vector<int>& arr) 
{
    int count = 0;
    for (const int& element : arr) {
        if (element % 2 == 1) {
            count++;
        }
    }
    return count;
}

int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << count_odd_numbers(arr) << endl;
    return 0;
}


