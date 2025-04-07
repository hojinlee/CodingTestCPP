#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main()
{
    queue<int, list<int>> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);

    cout << myQueue.front() << endl;
    myQueue.pop();
    myQueue.pop();

    // 큐의 값 출력을 위해 큐가 빌 때까지
    // 맨 앞 값을 출력하고 꺼내는 일을 반복
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop(); // 출력한 값은 꺼내기
    }
    cout << endl;

    return 0;
}