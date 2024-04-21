#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int board[110][110];
int N;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int r, c, d, g;
vector<tuple<int,int,int,int,int>> vt;

void    dragon(int cur)
{
    if (cur == g + 1)
        return ;
    if (cur == 0) {
        int cd = d;
        board[r][c] = 1;
        int nr = r + dx[d]; int nc = c + dy[d];
        board[nr][nc] = 1;
        vt.push_back({r, c, nr, nc, cd});
        dragon(cur + 1);
    }
    else {
        int count = vt.size() - 1;
        for (int i = vt.size() - 1; i >= 0; i--) {
            int cr = get<2>(vt[count]);
            int cc = get<3>(vt[count]);
            int cd = get<4>(vt[i]);
            int nd = cd + 1;
            if (nd > 3) nd = 0;
            int nr = cr + dx[nd]; 
            int nc = cc + dy[nd];
            board[nr][nc] = 1;
            count += 1;
            vt.push_back({cr, cc, nr, nc, nd});
        }
        dragon(cur + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> c >> r >> d >> g;
        dragon(0);
        vt.clear();
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] != 0 && board[i+1][j] != 0 && board[i][j+1] != 0 && board[i+1][j+1] != 0)
                ans += 1;
        }
    }
    cout << ans;
    return 0;
}