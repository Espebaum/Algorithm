#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int board[110][110];
int N;
int K;
deque<pair<int,int>>snake;
int L;
queue<pair<int,char>>tu;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int d = 1;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        board[r-1][c-1] = 3;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int X; char C;
        cin >> X >> C;
        tu.push({X, C});
    }
    snake.push_back({0, 0});
    for (int i = 0; i < snake.size(); i++)
        board[snake[i].first][snake[i].second] = 2;
    while (1)
    {
        pair<int,int>cur = tu.front();
        if (cur.first == ans) {
            if (cur.second == 'D') {
                d += 1;
                if (d == 4) d = 0;
            }
            else {
                d -= 1;
                if (d == -1) d = 3;
            }
            tu.pop();
        }
        pair<int,int>head = snake[0];
        int nbx = head.first + dx[d];
        int nby = head.second + dy[d];
        if (nbx < 0 || nbx >= N || nby < 0 || nby >= N)
            break ;
        if (board[nbx][nby] == 2 || board[nbx][nby] == 1)
            break ;
        if (board[nbx][nby] == 3) {
            snake.push_front({nbx, nby});
        } else {
            snake.push_front({nbx, nby});
            board[snake[snake.size() - 1].first][snake[snake.size() - 1].second] = 0;
            snake.pop_back();
        }
        for (int i = 0; i < snake.size(); i++)
            board[snake[i].first][snake[i].second] = 2;
        ans += 1;
    }
    cout << ans+1;

    return 0;
}