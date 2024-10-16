// boj s4 14425
// 문자열 집합
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

using int32 = long;
using int64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> s;

    for(int i=0; i<N; i++)
    {
        string input;
        cin >> input;

        s.insert(input);
    }

    int result = 0;
    for(int i=0; i<M; i++)
    {
        string input;
        cin >> input;

        if (s.find(input) != s.end())
            result++;
    }

    cout << result;

    return 0;
}


// Trie를 이용한 풀이
/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

using int32 = long;
using int64 = long long;


class Node
{
public:
    Node* next[26]{};
    bool isEnd = false;
    Node()
    {
        fill(next, next + 26, nullptr);
    }

    ~Node()
    {
        for(auto& child : next)
        {
            delete child;
        }
    }

    // 문자열 삽입 함수
    void insert(const char* key)
    {
        if (*key == 0)
            isEnd = true;
        else
        {
            int next_idx = *key - 'a';

            if (next[next_idx] == nullptr)
                next[next_idx] = new Node();

            next[next_idx]->insert(key + 1);
        }
    }

    // 문자열 찾기 함수
    Node* find(const char* key)
    {
        if (*key == 0)
            return this;

        int next_idx = *key - 'a';

        if (next[next_idx] == nullptr)
            return nullptr;

        return next[next_idx]->find(key + 1);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Node* node = new Node();

    for(int i=0; i<N; i++)
    {
        char input[501];
        cin >> input;

        node->insert(input);
    }

    int result = 0;

    for(int i=0; i<M; i++)
    {
        char input[501];
        cin >> input;

        Node* text = node->find(input);

        if (text && text->isEnd)
            result++;
    }

    cout << result;

    
    return 0;
}
*/