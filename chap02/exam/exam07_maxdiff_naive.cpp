#include <iostream>
#include <vector>
using namespace std;
 
int max_diff(vector<int> data)
{
    int ans = 0;
    for(int i = 0; i < data.size() - 1; i++)
    {
        for(int j = i + 1; j < data.size(); j++)
        {
            ans = max(data[j] - data[i], ans);
        }
    }
 
    return ans;
}
 
int main() {
    vector<int> data = { 3, 5, 7, 1, 4, 6 };
    cout << max_diff(data) << endl; // 5
    return 0;
}