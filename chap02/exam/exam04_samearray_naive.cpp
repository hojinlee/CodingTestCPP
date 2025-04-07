#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool same_array(vector<int>& data1, vector<int>& data2) 
{
    sort(data1.begin(), data1.end());  
    sort(data2.begin(), data2.end());  

    for(int i = 0; i < data1.size(); i++)
    {
        if(data1[i] != data2[i]) return false;
    }

    return true;
}

int main() 
{
    vector<int> data1 = { 1, 4, 5, 3, 2};
    vector<int> data2 = { 2, 5, 4, 3, 1};
    vector<int> data3 = { 3, 7, 1, 4, 5};
    cout << same_array(data1, data2) << endl; // 1
    cout << same_array(data1, data3) << endl; // 0
    return 0;
}
