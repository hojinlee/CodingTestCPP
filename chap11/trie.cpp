#include <iostream>

using namespace std;

// 문자와 문자열을 소문자로 가정하고 작성한 trie코드입니다.
struct node
{
    node *child[26]; // 알파벳 갯수만큼 자식을 가짐
    int value;       // 노드의 값, 여기서는 단어의 출현 횟수
    bool finish;     // 하나의 단어 완성 여부
    node()           // 노드의 생성자
    {
        // 알파벳 갯수만큼 순회
        for (int i = 0; i < 26; i++)
        {
            // 노드의 자식 포인터를 초기화
            child[i] = nullptr;
        }
        value = 0;      // 0으로 초기화
        finish = false; // 단어가 끝나지 않았다고 초기화
    }

    ~node() // 노드의 소멸자
    {
        // 알파벳 갯수만큼 순회
        for (int i = 0; i < 26; i++)
        {
            if (child[i])
                delete child[i]; // 할당 메모리를 해제
        }
    }
};

// 트라이 클래스
class trie
{
private:
    node root; // 루트 노드

public:
    // 트라이에 단어(str)와 값(value)을 삽입
    void insert(const string &str, const int &value)
    {
        // 탐색에 사용할 노드 포인터
        node *cur = &root;

        // 문자를 하나씩 읽어서 문자열에 해당하는 트리를 완성
        for (int i = 0; i < str.size(); i++)
        {
            // 다음 노드가 존재하지 않으면 새로 할당
            if (cur->child[str[i] - 'a'] == nullptr)
            {
                cur->child[str[i] - 'a'] = new node();
            }
            cur = cur->child[str[i] - 'a']; // 현재 문자에 해당하는 포인터를 cur로 변경
        }

        cur->finish = true; // 단어 완성을 표시
        cur->value = value; // 마지막 노드에 값을 기록
    }

    // 트라이에서 문자열 찾아서 값을 반환
    int find(const string &str)
    {
        // 탐색에 사용할 노드 포인터
        node *cur = &root;

        // 문자를 하나씩 읽어서 문자열에 해당하는 트리를 완성
        for (int i = 0; i < str.size(); i++)
        {
            // 다음 노드가 존재하지 않으면 -1을 반환
            if (cur->child[str[i] - 'a'] == nullptr)
            {
                return -1;
            }
            cur = cur->child[str[i] - 'a']; // 현재 문자에 해당하는 포인터를 cur로 변경
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
    trie t1;
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