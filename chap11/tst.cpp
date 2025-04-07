#include <iostream>

using namespace std;

// 문자와 문자열을 소문자로 가정하고 작성한 삼진 검색 트리 코드입니다.

// 노드 구조체
struct node
{
    node *child[3]; // 0: 현재 값보다 작은, 1: 현재 값과 같은, 2: 현재 값보다 큰
    char ch;        // 현재 노드에 해당하는 문자
    int value;      // 노드가 가지는 값
    bool finish;    // 하나의 단어 완성 여부

    node() // 노드의 생성자
    {
        // 모든 자식을 순회
        for (int i = 0; i < 3; i++)
        {
            // 노드의 자식 포인터를 초기화

            child[i] = nullptr;
        }
        ch = ' ';       // 빈 문자로 초기화
        value = 0;      // 0으로 초기화
        finish = false; // 단어의 미완성으로 초기화
    }

    ~node() // 노드의 소멸자
    {
        // 모든 자식을 순회
        for (int i = 0; i < 3; i++)
        {
            if (child[i])        // 자식에 할당된 메모리가 있으면
                delete child[i]; // 자식의 메모리 해제
        }
    }

    // 문자 삽입
    node *insert(char c)
    {
        node *cur = this; // 자신을 cur 포인터로 초기화
        if (ch == ' ')    // 현재 노드가 빈 값이라면, 현재 문자를 삽입
        {
            ch = c;
        }
        else // 현재 노드에 해당하는 문자가 있다면
        {
            // 삽입하려는 문자가 현재 노드의 문자보다 작은 값이면
            if (ch > c)
            {
                if (child[0] == nullptr)   // 자식에 메모리가 할당되어 있지 않다면
                    child[0] = new node(); // 새로 메모리를 할당
                cur = child[0]->insert(c); // 문자를 자식 0에 삽입하고 해당 포인터를 cur에 할당
            }
            // 삽입하려는 문자가 현재 노드의 문자보다 큰 값이면
            else if (ch < c)
            {
                if (child[2] == nullptr)   // 자식에 메모리가 할당되어 있지 않다면
                    child[2] = new node(); // 새로 메모리를 할당
                cur = child[2]->insert(c); // 문자를 자식 2에 삽입하고 해당 포인터를 cur에 할당
            }
        }

        return cur; // c를 삽입한 노드의 포인터를 반환
    }

    // 문자가 있는 노드를 반환
    node *find(char c)
    {
        if (ch == c)
            return this;
        if (ch > c)
        {
            if (child[0] == nullptr)
                return nullptr;
            return child[0]->find(c);
        }

        if (ch < c)
        {
            if (child[2] == nullptr)
                return nullptr;
            return child[2]->find(c);
        }

        return nullptr;
    }
};

// 삼진 검색 트리 클래스
class tst
{
private:
    node root; // 트리의 루트 노드

public:
    // 트리에 단어와 값을 삽입
    void insert(const string &str, const int &value)
    {
        // 탐색에 사용할 노드 포인터
        node *cur = &root;

        // 문자를 하나씩 읽어서 문자열에 해당하는 트리를 완성
        for (int i = 0; i < str.size() - 1; i++)
        {
            cur = cur->insert(str[i]); // 각 문자를 현재 노드에 삽입

            // 다음 노드가 존재하지 않으면 새로 할당
            if (cur->child[1] == nullptr)
                cur->child[1] = new node();
            cur = cur->child[1]; // 현재 문자에 해당하는 포인터를 cur로 변경
        }

        // 마지막 노드를 삽입
        cur = cur->insert(str[str.size() - 1]);
        // 마지막 노드에 값을 기록
        cur->finish = true; // 단어 완성을 표시
        cur->value = value; // 마지막 노드에 값을 기록
    }

    // 단어를 트리에 삽입
    int find(const string &str)
    {
        // 탐색에 사용할 노드 포인터
        node *cur = &root;

        // 문자를 하나씩 읽어서 단어에 해당하는 트리를 완성
        for (int i = 0; i < str.size(); i++)
        {
            cur = cur->find(str[i]);
            // 대상 문자열을 찾지 못하면 -1을 반환
            if (cur == nullptr)
                return -1;

            if (i != str.size() - 1) // 단어의 끝이 아닐때만
            {
                cur = cur->child[1]; // 현재 노드의 자식을 다음 현재 노드로 변경
            }
        }

        // 대상 문자열을 찾지 못하면 -1을 반환
        if (!cur->finish)
            return -1;

        // 해당 노드의 값 반환
        return cur->value;
    }
};

int main()
{
    tst t1;
    t1.insert("aero", 100); // aero가 100번 출현했다고 삽입
    t1.insert("ape", 50);   // ape가 50번 출현했다고 삽입
    t1.insert("app", 10);   // app가 10번 출현했다고 삽입
    t1.insert("apple", 30); // apple가 30번 출현했다고 삽입
    t1.insert("bar", 20);   // bar가 20번 출현했다고 삽입
    t1.insert("box", 25);   // box가 25번 출현했다고 삽입
    t1.insert("boy", 100);  // boy가 100번 출현했다고 삽입

    cout << t1.find("box") << endl; // box를 찾기
    cout << t1.find("aaa") << endl; // aaa를 찾기
    return 0;
}