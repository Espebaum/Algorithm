#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int b[5][5][5];
int co[5][5][5];
vector<pair<int,int>>st(5);
int s_isused[10];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dis[5][5][5];
vector<int>answers;
int t;

void    bfs()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++)
                dis[i][j][k] = -1;
        }
    }
    if (co[0][0][0] == 0 || co[4][4][4] == 0)
        return ;
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    dis[0][0][0] = 0;
    while (!q.empty())
    {
        tuple<int,int,int>cur = q.front(); q.pop();
        int cz = get<0>(cur);
        int cx = get<1>(cur);
        int cy = get<2>(cur);
        if (cz == 4 && cx == 4 && cy == 4) {
            int ans = dis[4][4][4];
            answers.push_back(ans);
            if (ans == 12)
                t = ans;
            return ;
        }
        for (int dir = 0; dir < 6; dir++) {
            int nz = cz + dz[dir];
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || nz < 0 || nz > 4) continue;
            if (dis[nz][nx][ny] != -1 || co[nz][nx][ny] == 0) continue;
            dis[nz][nx][ny] = dis[cz][cx][cy] + 1;
            q.push({nz,nx,ny});
        }
    }
}

void    copy() 
{
    for (int i = 0; i <= 4; i++) {
        if (st[i].second == 0) {
            int cur = st[i].first;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    co[i][r][c] = b[cur][r][c];
                }
            }
        }
        else if (st[i].second == 3) {
            int cur = st[i].first;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    co[i][r][c] = b[cur][c][4 - r];
                }
            }
        }
        else if (st[i].second == 2) {
            int cur = st[i].first;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    co[i][r][c] = b[cur][4 - r][4 - c];
                }
            }
        }
        else if (st[i].second == 1) {
            int cur = st[i].first;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    co[i][r][c] = b[cur][4 - c][r];
                }
            }
        }
    }
}

void    solve(int k)
{
    if (t == 12)
        return ;
    if (k == 5) {
        copy();
        bfs();
        return ;
    }
    for (int i = 0; i <= 3; i++) {
        st[k].second = i;
        solve(k + 1);
    }
}

void    force(int k)
{
    if (t == 12)
        return ;
    if (k == 5) {
        solve(0);
        return ;
    }
    for (int i = 0; i < 5; i++) {
        if (!s_isused[i]) {
            st[k].first = i;
            s_isused[i] = 1;
            force(k + 1);
            s_isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> b[i][j][k];
    force(0);
    if (answers.empty())
        cout << -1;
    else {
        sort(answers.begin(), answers.end());
        cout << answers[0] << '\n';
    }
    return 0;
}