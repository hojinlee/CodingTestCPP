#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 물건 구조체 정의
struct item
{
    int value;  // 가치
    int weight; // 무게
};

bool compare(item &lhs, item &rhs) // 비교 함수를 정의합니다.
{
    // 단위 무게당 가치를 구해서 내림차순으로 비교합니다.
    float vL = lhs.value / (float)lhs.weight;
    float vR = rhs.value / (float)rhs.weight;
    return (vL > vR);
}

float fractional_knapsack(int w, vector<item> items) // 분할 배낭 문제 함수를 정의합니다.
{
    // 내림차순으로 정렬합니다. 단위 무게당 가치가 높은 것부터 선택하기 위함입니다.
    sort(items.begin(), items.end(), compare);

    float ans = 0.0;                       // 결과 값을 저장할 변수입니다.
    for (int i = 0; i < items.size(); i++) // 모든 아이템을 순회합니다.
    {
        if (w - items[i].weight >= 0) // 쪼개지 않고 담을 수 있다면
        {
            w -= items[i].weight;
            ans += items[i].value;
        }
        else // 쪼개 담고 반복문을 빠져나갑니다.
        {
            // 쪼개 담을 물건의 가치를 구하여 더합니다.
            ans += items[i].value * w / (float)items[i].weight;
            w = 0;
            break;
        }
    }

    return ans; // 결과 값을 반환합니다.
}

int main()
{
    // k: 18, n: 3(3원/3kg, 10원/5kg, 36원/12kg)
    cout << fractional_knapsack(18, {{3, 3}, {10, 5}, {36, 12}}) << endl;
    // k: 15, n: 3(3원/4kg, 10원/5kg, 20원/8kg)
    cout << fractional_knapsack(15, {{3, 4}, {10, 5}, {20, 8}}) << endl;

    return 0;
}