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
#include <cmath>
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int N, K;
int t[200020];
int vis[200020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    fill(t, t+200020, -1);
    t[N] = 0;
    vis[N] = 1;
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K)
            break ;
        for (int move = 1; move <= 3; move++) {
            int new_cur;
            if (move == 1) 
                new_cur = cur + 1;
            else if (move == 2)
                new_cur = cur - 1;
            else
                new_cur = cur * 2;
            if (new_cur < 0 || new_cur > 200000 || vis[new_cur] >= 2)
                continue ;
            int value;
            if (move == 3)
                value = t[cur];
            else
                value = t[cur] + 1;
            if (t[new_cur] == -1)
                t[new_cur] = max(t[new_cur], value);
            else
                t[new_cur] = min(t[new_cur], value);
            vis[new_cur]++;
            q.push(new_cur);
        }
    }
    cout << t[K] << '\n';
    return 0;
}