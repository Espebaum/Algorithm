#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

string  s;
string  board[15];
int dx[4] = {-1, 1, 0, 0}; // 북,남,서,동
int dy[4] = {0, 0, -1, 1};
int N, M;
int ans = 11;
bool isBlue = false;
int irx; int iry;
int ibx; int iby;
pair<int,int>hole;

bool red = false; 
bool blue = false; 
void    solve(int rx, int ry, int bx, int by, int cnt);

void    moveR(int dir, int rx, int ry, int bx, int by, int cnt)
{   
    while (1)
    {
        if (board[rx][ry] == 'O') {
            red = 1;
            break;
        }
        int nx = rx + dx[dir];
        int ny = ry + dy[dir];
        if (board[nx][ny] == '#') 
            break ;
        if (nx == bx && ny == by && board[bx][by] != 'O')
            break ;
        rx += dx[dir];
        ry += dy[dir];
    }
    irx = rx;
    iry = ry;
}

void    moveB(int dir, int rx, int ry, int bx, int by, int cnt)
{
    while (1)
    {
        if (board[bx][by] == 'O') {
            blue = 1;
            break ;
        }
        int nx = bx + dx[dir];
        int ny = by + dy[dir];
        if (board[nx][ny] == '#') 
            break ;
        if (nx == rx && ny == ry && board[rx][ry] != 'O')
            break ;
        bx += dx[dir];
        by += dy[dir];
    }
    ibx = bx;
    iby = by;
}

void    move(int dir, int rx, int ry, int bx, int by, int cnt)
{
    irx = rx; iry = ry; ibx = bx; iby = by;
    moveR(dir, irx, iry, ibx, iby, cnt);
    moveB(dir, irx, iry, ibx, iby, cnt);
    moveR(dir, irx, iry, ibx, iby, cnt);
    moveB(dir, irx, iry, ibx, iby, cnt);
    if (board[irx][iry] == 'O' && board[ibx][iby] != 'O') {
        ans = min(ans, cnt);
        return ;
    }
    solve(irx, iry, ibx, iby, cnt);
}

void    solve(int rx, int ry, int bx, int by, int cnt)
{
    if (cnt > 10) return;
    move(0, rx, ry, bx, by, cnt + 1); // 북
    move(1, rx, ry, bx, by, cnt + 1); // 남
    move(2, rx, ry, bx, by, cnt + 1); // 서
    move(3, rx, ry, bx, by, cnt + 1); // 동
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        board[i] = s;
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'O')
                hole = {i, j};
            else if (board[i][j] == 'R') {
                irx = i; iry = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                ibx = i; iby = j;
                board[i][j] = '.';
            }
        }
    }
    solve(irx, iry, ibx, iby, 0);
    if (ans == 11) {
        cout << -1; return 0;
    }
    cout << ans;
    return 0;
}