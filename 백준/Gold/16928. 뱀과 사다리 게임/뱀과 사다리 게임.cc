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

int     board[102];
bool    vis[102];
int N, M, x, y;

void    solve(int x, int c)
{
    queue<pair<int,int>> q;
    q.push({x, c});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int nx = cur + i;
            if (nx == 100) {
                cout << cnt + 1;
                return ;
            }
            else if (nx < 100) {
                while (board[nx] != 0) {
                    nx = board[nx];
                }
                if (!vis[nx]) {
                    q.push(make_pair(nx, cnt + 1)); 
                    vis[nx] = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        board[x] = y; 
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        board[x] = y;
    }
    solve(1, 0);
    return 0;
}