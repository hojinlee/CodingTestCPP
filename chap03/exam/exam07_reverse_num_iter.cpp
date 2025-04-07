#include <iostream>
using namespace std;

int reverse_num_iter(int num)
{
    int ans = 0; // 결과값을 저장할 변수
    while(num != 0) 
    {
        int digit = num % 10; // 1의 자리 수를 구합니다.
        ans = ans * 10 + digit; // 기존에 구한 값을 한자리 올리고 새로운 수를 더합니다.        
        num /= 10;
    }
    
    return ans;
}

int main()
{
    cout << reverse_num_iter(1234) << endl; // 1234를 거꾸로 뒤집기
    return 0;
}
