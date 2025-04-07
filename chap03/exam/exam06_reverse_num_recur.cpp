#include <iostream>
using namespace std;

int reverse_num_recur(int num, int ans = 0) // ans의 디폴트 값으로 0을 지정합니다.
{
    if(num == 0) // 종료 조건은 num이 더이상 처리할 수 없을 때인 0입니다.
        return ans; // 결과를 반환합니다.
    
    int digit = num % 10; // 1의 자리 수를 구합니다.
    ans = ans * 10 + digit; // 기존에 구한 값을 한자리 올리고 새로운 수를 더합니다.
    return reverse_num_recur(num / 10, ans); 
}

int main()
{
    cout << reverse_num_recur(1234) << endl; // 1234를 거꾸로 뒤집기
    return 0;
}
