#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, K;
int dist[202020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N; cin >> K;
    queue<int>  q;

    fill(dist, dist + 202020, -1);

    dist[N] = 0;
    q.push(N);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K)
            break ;
        for (int dir = 0; dir < 3; dir++)
        {
            int newcur;
            if (dir == 0)
                newcur = cur + 1;
            else if (dir == 1)
                newcur = cur - 1;
            else
                newcur = cur * 2;
            if (newcur < 0 || newcur > 202020 || dist[newcur] >= 0)
                continue ;
            dist[newcur] = dist[cur] + 1;
            q.push(newcur);
        }
    }
    cout << dist[K];
    return 0;
}