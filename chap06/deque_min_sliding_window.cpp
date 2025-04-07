#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void mins_sliding_window(vector<int>& data, int k)
{
    vector<int> ret;
    deque<int> dq;

    for (int i = 0; i < data.size(); i++)
    {
        // 덱의 맨 앞 원소가 슬라이딩 윈도우 범위를 벗어나면 꺼낸다.
        if (!dq.empty() && i - dq.front() == k)
            dq.pop_front();

        // 현재 값보다 작은 값은 제거합니다
        while (!dq.empty() && data[i] < data[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        // 슬라이딩 윈도우에 모든 원소가 찼을 때부터 최솟값을 결과에 넣습니다.
        if (i >= k - 1) // k가 3일 때, i가 0, 1일 때는 슬라이딩 윈도우는 2개의 원소만 있습니다.
        {
            ret.push_back(data[dq.front()]);
        }
    }

    for (int i : ret)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> data = { 1, 4, 2, 3, 1, 5 };
    mins_sliding_window(data, 3); 

    return 0;
}