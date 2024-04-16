#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int board[110][110];
int saro[110][110];
int N, L;
bool cango;
int ans;

void    ud()
{
    // 위에서 아래
    for (int c = 0; c < N; c++) {
        cango = true;
        for (int r = 0; r < N - 1; r++) {
            if (board[r][c] < board[r + 1][c]) {
                // 올라가는 경사
                if (board[r][c] + 1 != board[r + 1][c]) {
                    cango = false; break ;
                }
                int cur = board[r][c];
                for (int i = 0; i < L; i++) {
                    if (r - i < 0 || board[r - i][c] != cur || saro[r - i][c] == 6 || saro[r - i][c] == 7) {
                        cango = false; break ;
                    }
                }
                if (!cango)
                    break ;
                else {
                    for (int i = 0; i < L; i++) {
                        saro[r - i][c] = 6;
                    }
                }
            } 
            else if (board[r][c] > board[r + 1][c]) {
                // 내려가는경사
                if (board[r][c] != board[r + 1][c] + 1) {
                    cango = false; break ;
                }
                int cur = board[r + 1][c];
                for (int i = 0; i < L; i++) {
                    if (r + 1 + i >= N || board[r + 1 + i][c] != cur || saro[r + 1 + i][c] == 6 || saro[r + 1 + i][c] == 7) {
                        cango = false; break ;
                    }
                }
                if (!cango)
                    break ;
                else {
                    for (int i = 0; i < L; i++) {
                        saro[r + 1 + i][c] = 7;
                    }
                }
            }
        }
        if (cango) {
            ans += 1;
        }
        else {
            for (int i = 0; i < N; i++)
                if (saro[i][c] == 6 || saro[i][c] == 7)
                    saro[i][c] = 0;
        }
    }
}

void    lr()
{
    // 왼쪽에서 오른쪽
    for (int r = 0; r < N; r++) {
        cango = true;
        for (int c = 0; c < N - 1; c++) {
            if (board[r][c] < board[r][c + 1]) {
                // 올라가는 경사
                if (board[r][c] + 1 != board[r][c + 1]) {
                    cango = false; break ;
                }
                int cur = board[r][c];
                for (int i = 0; i < L; i++) {
                    if (c - i < 0 || board[r][c - i] != cur || saro[r][c - i] == 4 || saro[r][c - i] == 5) {
                        cango = false; break ;
                    }
                }
                if (!cango)
                    break ;
                else
                    for (int i = 0; i < L; i++)
                        saro[r][c - i]  = 4;
            }
            else if (board[r][c] > board[r][c + 1]) {
                // 내려가는 경사
                if (board[r][c] != board[r][c + 1] + 1) {
                    cango = false; break ;
                }
                int cur = board[r][c + 1];
                for (int i = 0; i < L; i++) {
                    if (c + 1 + i >= N || board[r][c + 1 + i] != cur || saro[r][c + 1 + i] == 4 || saro[r][c + 1 + i] == 5) {
                        cango = false; break ;
                    }
                }
                if (!cango)
                    break ;
                else
                    for (int i = 0; i < L; i++)
                        saro[r][c + 1 + i] = 5;
            }
        }
        if (cango)
            ans += 1;
        else {
            for (int i = 0; i < N; i++)
                if (saro[r][i] == 4 || saro[r][i] == 5)
                    saro[r][i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cin >> board[i][j];
    }
    lr();
    ud();
    cout << ans << '\n';
    return 0;
}