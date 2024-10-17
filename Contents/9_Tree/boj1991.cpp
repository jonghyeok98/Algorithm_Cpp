// boj s1 1991
// 트리 순회
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

static pair<int, int>Node[26];

void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        char root, left, right;
        cin >> root >> left >> right;

        int root_idx = root - 'A';

        if (left == '.')
            Node[root_idx].first = -1;
        else
            Node[root_idx].first = left-'A';

        if (right == '.')
            Node[root_idx].second= -1;
        else
            Node[root_idx].second = right - 'A';
    }

    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    
    return 0;
}

void preOrder(int now)
{
    if (now == -1)
        return;

    // 루트 노드 -> 왼쪽 자식 노드 -> 오른쪽 자식 노드 순으로 방문
    cout << static_cast<char>(now + 'A');
    preOrder(Node[now].first);
    preOrder(Node[now].second);
}

void inOrder(int now)
{
    if (now == -1)
        return;

    // 왼쪽 자식 노드 -> 루트 노드 -> 오른쪽 자식 노드 순으로 방문
    inOrder(Node[now].first);
    cout << static_cast<char>(now + 'A');
    inOrder(Node[now].second);
}

void postOrder(int now)
{
    if (now == -1)
        return;

    // 왼쪽 자식 노드 -> 오른쪽 자식 노드 -> 루트 노드 순으로 방문
    postOrder(Node[now].first);
    postOrder(Node[now].second);
    cout << static_cast<char>(now + 'A');
}
