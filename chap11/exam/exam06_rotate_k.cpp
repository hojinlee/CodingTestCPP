#include <iostream>
#include <string>
#include <algorithm> // reverse 메소드 사용을 위해 선언

using namespace std;

// ans을 k만큼 오른쪽으로 회전하여 반환
string rotate_k(const string &str, int k)
{
    // k가 문자열 길이보다 큰 경우는 k를 문자열 길이로 나눈 나머지 만큼 이동
    k %= str.size();

    // 결과 저장을 위한 변수 선언, 입력값을 바로 수정하여 결과에 저장하기 위해 복사 생성
    string ans(str);

    reverse(ans.begin(), ans.end());       // 문자열 전체를 뒤집기
    reverse(ans.begin(), ans.begin() + k); // 회전된 앞부분을 뒤집어서 정상순으로 만들기
    reverse(ans.begin() + k, ans.end());   // 뒷부분을 뒤집어서 정상순으로 만들기

    return ans;
}

int main()
{
    cout << rotate_k("abcde", 2) << endl; // 회전된 결과 출력

    return 0;
}
