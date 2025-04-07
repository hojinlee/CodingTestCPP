#include <iostream>
#include <stack>
#include <limits>

using namespace std;

// 중복 괄호 찾기
bool findDuplicateBracket(const string &expr)
{
	stack<char> stk;
	int cnt = 0;

	for (char ch : expr)
	{
		switch (ch)
		{
		case ')':	 // 닫는 괄호
			cnt = 0; // 여는 괄호와 닫는 괄호 사이의 문자 수
			// 여는 괄호를 찾을 때 까지 반복
			while (stk.size() != 0 && stk.top() != '(')
			{
				stk.pop();
				cnt++;
			}
			if (cnt < 2)
				return true; // 중복 괄호 발견
			break;

		default: // 닫는 괄호 이외의 문자는 스택에 삽입
			stk.push(ch);
		}
	}

	return false;
}

int main()
{
	string str;
	cin >> str;
	cout << findDuplicateBracket(str) << endl;

	return 0;
}