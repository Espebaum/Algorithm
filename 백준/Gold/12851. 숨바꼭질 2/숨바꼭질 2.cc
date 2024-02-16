#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int board[202020];
int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>K;
    fill(board,board+202020,-1);
    queue<int>q;
    q.push(N);
    board[N] = 0;
    int ans = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K) {
            ans += 1;
            continue;
        }
        for (int i = 0; i < 3; i++) {
            int ncur;
            if (i == 0) 
                ncur = cur - 1;
            else if (i == 1)
                ncur = cur + 1;
            else
                ncur = cur * 2;
            if (ncur > 101010 || ncur < 0)
                continue;
            // cout << "ncur: " << ncur << '\n';
            if (board[ncur] != -1) {
                if (board[cur] + 1 != board[ncur])
                    continue;
            }
            board[ncur] = board[cur] + 1;
            q.push(ncur);
        }
    }
    cout << board[K] << '\n';
    cout << ans;

    return 0;
}