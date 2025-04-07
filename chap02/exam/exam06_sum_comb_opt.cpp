// O(n^2)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum_combination(const vector<int>& data) 
{
    int ans = 0;
    
    for(int i = 0; i < data.size(); i++) 
    {
        ans += data[i];
    }
    
    /*
    (a, b, c,)에서 2개를 고르는 조합은 (a,b), (a,c), (b,c)로
    각 원소는 각 조합의 쌍에 2번 포함됩니다.
    (a, b, c, d)에서 2개를 고르는 조합은 (a,b), (a,c), (a,d), (b,c), (b,d), (c,d)로
    각 원소는 각 조합의 쌍에 3번 포함됩니다.
    n 크기의 배열에서 2개의 원소를 고르는 조합은 각 원소가 n-1번 포함됩니다. 
    조합의 모든 원소의 합은 배열의 총합은 sum(n)*n-1 입니다.
    */
        
    return ans * (data.size() - 1);
}

int main() 
{
    vector<int> data = { 5, 8, 2, 1, 4 };
    
    cout << sum_combination(data) << endl; // 80

    return 0;
}

