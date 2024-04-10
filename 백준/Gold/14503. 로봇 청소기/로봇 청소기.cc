#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int board[55][55];
int clean[55][55];
int N, M; 
int r, c, d;
int dx[4] = {-1, 0, 1, 0}; // "북0 동1 남2 서3" 
int dy[4] = {0, 1, 0, -1}; // 
    
bool    check()
{
    for (int dir = 0; dir < 4; dir++) 
    {
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        if (nr < 0 || nr > N || nc < 0 || nc > M)
            continue; 
        if (board[nr][nc] != 0)
            continue ;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    while (1)
    {
        if (board[r][c] != 2)
            board[r][c] = 2;
        if (check()) {
            if (d == 0) {
                d = 3; // 서
            } else if (d == 3) {
                d = 2; // 남
            } else if (d == 2) {
                d = 1; // 동
            } else {
                d = 0; // 북
            }
            int tr = r + dx[d];
            int tc = c + dy[d];
            if (tr < 0 || tr > N || tc < 0 || tc > M)
                continue ;
            if (board[tr][tc] == 0) {
                r = tr;
                c = tc;
            }
        } else {
            int bd = d + 2;
            if (bd > 3)
                bd -= 4;
            int br = r + dx[bd];
            int bc = c + dy[bd]; 
            if (board[br][bc] != 1) {
                r = br; c = bc;
            } else {
                break ;
            }
        }
    } 
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2)
                cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}