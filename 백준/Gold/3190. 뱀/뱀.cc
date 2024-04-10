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
// d 0 북 1 동 2 남 3 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int d = 1;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // if (i == 0 || i == N - 1) {
            //     board[i][j] = 1;
            // } else {
            //     if (j == 0 || j == N - 1) {
            //         board[i][j] = 1;
            //     } else {
            //         board[i][j] = 0;
            //     }
            // }
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        board[r-1][c-1] = 3; // 사과 3
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int X; char C;
        cin >> X >> C;
        tu.push({X, C});
    }
    snake.push_back({0, 0});
    for (int i = 0; i < snake.size(); i++) {
        board[snake[i].first][snake[i].second] = 2;
    }

    // cout << "처음\n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << board[i][j] << ' ';
    //     } cout << '\n';
    // }
    // 1 -> 벽, 2 -> 뱀, 3 -> 사과
    while (1)
    {
        pair<int,int>cur = tu.front();
        if (cur.first == ans) {
            // d 0 북 1 동 2 남 3 서
            // cout << "방향 변경: " << cur.first << ' ' << (char)cur.second << '\n';
            if (cur.second == 'D') {
                d += 1;
                if (d == 4)
                    d = 0;
            }
            else {
                d -= 1;
                if (d == -1)
                    d = 3;
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

        for (int i = 0; i < snake.size(); i++) {
            board[snake[i].first][snake[i].second] = 2;
        }

        ans += 1;
        // cout << ans << "초 경과\n";
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << board[i][j] << ' ';
        //     } cout << '\n';
        // }
    }
    cout << ans+1;

    return 0;
}