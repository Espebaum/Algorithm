#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int R, C, T;
int board[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void    upper(int r) // {3, 1}
{
    for (int i = r-2; i >= 1; i--) {
        board[i+1][1] = board[i][1];
    }

    for (int j = 2; j <= C; j++) {
        board[1][j-1] = board[1][j];
    }

    for (int i = 2; i <= r; i++) {
        board[i-1][C] = board[i][C];
    }

    for (int j = C; j > 2; j--) {
        board[r][j] = board[r][j-1];
    }
    board[r][2] = 0;
} 

void    lower(int r)
{
    for (int i = r+1; i < R; i++) {
        board[i][1] = board[i+1][1];
    }
    for (int j = 1; j < C; j++) {
        board[R][j] = board[R][j+1];
    }
    for (int i = R; i > r; i--) {
        board[i][C] = board[i-1][C];
    }
    for (int j = C; j > 2; j--) {
        board[r][j] = board[r][j-1];
    }
    board[r][2] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>R>>C>>T;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            cin>>board[i][j];
    }

    while (T--)
    {
        vector<tuple<int,int,int>> vt;
        vector<pair<int,int>> vp;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (board[i][j] > 0) 
                    vt.push_back(make_tuple(i, j, board[i][j]));
                else if (board[i][j] == -1)
                    vp.push_back({i, j});
            }
        }
        for (int i = 0; i < vt.size(); i++) {
            int cx = get<0>(vt[i]); int cy = get<1>(vt[i]);
            int e = get<2>(vt[i])/5;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (nx < 1 || nx > R || ny < 1 || ny > C)
                    continue;
                if (board[nx][ny] == -1)
                    continue;
                board[cx][cy] -= e;
                board[nx][ny] += e;
            }
        }
        // if (T == 1) {
        //     for (int i = 1; i <= R; i++) {
        //         for (int j = 1; j <= C; j++)
        //             cout<<board[i][j]<<' ';
        //         cout << '\n';
        //     }
        // }
        upper(vp[0].first);
        lower(vp[1].first);
        // if (T == 1) {
        //     cout << '\n';
        //     for (int i = 1; i <= R; i++) {
        //         for (int j = 1; j <= C; j++)
        //             cout<<board[i][j]<<' ';
        //         cout << '\n';
        //     }
        // }
    }


    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            if (board[i][j] > 0)
                ans += board[i][j];
    }
    cout << ans;
    return 0;
}