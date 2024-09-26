// boj g5 2251
// 물통
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>

using namespace std;

using int32 = long;
using int64 = long long;

void BFS();
// 6가지 이동 케이스
// A->B, A->C, B->A, B->C, C->A, C->B
static int Sender[] = { 0, 0, 1, 1, 2, 2 };
static int Receiver[] = { 1, 2, 0, 2, 0, 1 };

// A와 B의 용량만 있으면 C의 용량을 알 수 있음
// [A][B][C]가 아닌 [A][B]로 C의 용량을 알 수 있음
static bool visited[201][201];

// C의 물의 양 정답
static bool answer[201];

// A, B, C의 용량을 저장
static int now[3];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> now[0] >> now[1] >> now[2];

    BFS();

    for(int i=0; i<201; i++)
    {
        if (answer[i])
            cout << i << " ";
    }

    return 0;
}


void BFS()
{
    queue < pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[now[2]] = true;      // 옮기지 않은 기본 상태 

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int A = cur.first;
        int B = cur.second;
        // C는 전체 물의 양에서 A와 B를 뺀 것
        int C = now[2] - A - B;

        // 6가지 케이스 진행
        for(int i=0; i<6; i++)
        {
            int next[] = { A,B,C };
            next[Receiver[i]] += next[Sender[i]];
            next[Sender[i]] = 0;

            // 옮겨야 하는 물의 용량이 초과된 경우
            if(next[Receiver[i]]>now[Receiver[i]])
            {
                // 차이 만큼 기존 물통에 보내고
                next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]];
                // 물통을 최대로 채움
                next[Receiver[i]] = now[Receiver[i]];
            }

            if(!visited[next[0]][next[1]])
            {
				// A와 B 방문체크
                visited[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));

                // A의 물의 양이 0인경우 C의 물의 양을 정답에 추가
                if (next[0] == 0)
                    answer[next[2]] = true;
            }

        }
    }

}
