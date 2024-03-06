#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

string mp[7];
int board[7][7];
int vis[7][7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<tuple<int,int,char>>vt;
int ans;
int arr[10];
int isused[25]; // 변경: 0부터 24까지 사용 여부 체크

int check()
{
    int cp = 7; // checkpoint
    int sp = 0; // 다솜 포인트
    int yp = 0; // 도연 포인트
    int sx = get<0>(vt[arr[0]]);
    int sy = get<1>(vt[arr[0]]);
    
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    if (mp[sx][sy] == 'Y') yp += 1;
    else sp += 1;
    cp -= 1;
    while (!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        int cx = cur.first;
        int cy = cur.second;
        if (yp >= 4)
            return 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
                continue ;
            if (!board[nx][ny] || vis[nx][ny])
                continue;
            if (mp[nx][ny] == 'Y') yp += 1;
            else sp += 1;        
            vis[nx][ny] = 1;
            cp -= 1;
            q.push({nx, ny});
        }
    }
    if (cp == 0) {
        return 1;
    } 
    return 0;
}

void solve(int k)
{
    if (k == 7) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int n1, n2;
        for (int i = 0; i < 7; i++) {
            int cx = get<0>(vt[arr[i]]);
            int cy = get<1>(vt[arr[i]]);
            board[cx][cy] = 1;
        }
        ans += check();
        return;
    }

    int st = 0;
    if (k != 0)
        st = arr[k-1]+1;
    
    for (int i = st; i < 25; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num = 0;
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        mp[i] = s;
        for (int j = 0; j < 5; j++) {
            vt.push_back({i, j, s[j]});
            num += 1;
        }
    }

    solve(0);
    cout << ans;
    return 0;
}
