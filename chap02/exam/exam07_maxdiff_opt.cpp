#include <iostream>
#include <vector>
using namespace std;

int max_diff(vector<int> data)
{
    int ans = 0;
    int min_value = data[0]; // 현재까지 가장 작은 값을 저장 
    for(int i = 1; i < data.size(); i++)
    {
        // 현재 값과 현재 이전까지 가장 작은 값의 차를 계산하여 최댓값을 갱신
        ans = max(data[i] - min_value, ans); 
        // 현재 값이 더 작다면 최솟값 갱신
        min_value = min(min_value, data[i]); 
    }
    
    return ans;
}

int main() {
    vector<int> data = { 3, 5, 7, 1, 4, 6 }; // 5
    cout << max_diff(data) << endl;
    return 0;
}