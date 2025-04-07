#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 현재 인덱스의 최대 부분 배열 합 = 이전 인덱스가 가질 수 있는 최대 부분 배열 합 + 현재 인덱스의 값
int maxsum_subarray(vector<int> data)
{
    int ans = data[0]; // 최대합을 data[0]의 값으로 초기화

    // ans_start와 ans_end는 최종 정답의 시작과 끝점에 대한 인덱스고
    // cur_start는 반복문에서 현재값의 시작점입니다.
    int ans_start(0), ans_end(0), cur_start(0);

    for (int i = 1; i < data.size(); i++) // 현재값에 대한 반복문
    {
        // 이전 부분 배열 합을 포함한 것과 아닌 것 중에 최댓값 찾기
        if (data[i] + data[i - 1] > data[i]) // 직전 값을 포함하면 값이 커지는 경우
        {
            data[i] += data[i - 1]; // 직전 값을 현재값에 더하기
        }
        else
        {
            // 직전 값을 포함해도 값이 안 커진다면
            cur_start = i; // 직전 값은 버리고, 현재 값으로 새로운 시작점 설정
        }

        if (ans <= data[i]) // 현재 값이 지금까지 정답보다 크거나 같다면
        {
            ans = data[i];         // 정답을 갱신
            ans_start = cur_start; // 현재 시작점을 결과 시작점으로 변경
            ans_end = i;           // 정답의 끝점을 현재 인덱스로 갱신
        }
    }
    cout << ans << ", " << ans_start << ", " << ans_end << endl;

    return ans;
}

int main()
{
    maxsum_subarray({1, -4, 5, -1, -2, 3, 8, -2});
    maxsum_subarray({1, -4, 5, -3, -2, -2, 3, 1});

    return 0;
}
