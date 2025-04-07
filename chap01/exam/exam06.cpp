#include <iostream>
#include <vector>
using namespace std;

void print_arr_elem(vector<int>& arr, int i)
{
    if(arr.size() <= i)
        return;
    cout << arr[i] << endl;
}

int main()
{
    vector<int> data = { 1,2,3 };
    print_arr_elem(data, 2);

    return 0;
}
