#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

int main()
{
    const int dq_size = 5;
    deque<int> dq(dq_size);
    
    iota(begin(dq), end(dq), 0); // dq에 값을 채우기
    for (auto& i : dq)
        cout << i << " "; // 0 1 2 3 4
    cout << endl;

    // 덱의 전반부를 순회하여 덱의 후반부와 맞바꾸기
    for (unsigned i = 0; i < dq_size / 2; i++) // 덱의 전반부 순회를 위해 나누기 2
    {
        swap(dq[i], dq[dq_size - 1 - i]);
    }

    for (auto& i : dq)
        cout << i << " "; // 4 3 2 1 0
    cout << endl;

    return 0;
}