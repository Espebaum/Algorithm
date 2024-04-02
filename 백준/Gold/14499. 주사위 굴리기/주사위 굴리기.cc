#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
int x, y;
int c;
int board[22][22];
int coms[1010];
int dice[7];

void    east(int x, int y)
{
    int t1, t3, t4, t6;
    t1 = dice[1];
    t3 = dice[3];
    t4 = dice[4];
    t6 = dice[6];

    dice[1] = t4;
    dice[3] = t1;
    dice[4] = t6;
    dice[6] = t3;

    if (board[x][y] != 0) {
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    else {
        board[x][y] = dice[6];
    }
    cout << dice[1] << '\n';
}

void    west(int x, int y)
{
    int t1, t3, t4, t6;
    t1 = dice[1];
    t3 = dice[3];
    t4 = dice[4];
    t6 = dice[6];

    dice[1] = t3;
    dice[3] = t6;
    dice[4] = t1;
    dice[6] = t4;

    if (board[x][y] != 0) {
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    else {
        board[x][y] = dice[6];
    }
    cout << dice[1] << '\n';
}

void    north(int x, int y)
{
    int t1, t2, t5, t6;
    t1 = dice[1];
    t2 = dice[2];
    t5 = dice[5];
    t6 = dice[6];

    dice[1] = t5;
    dice[2] = t1;
    dice[5] = t6;
    dice[6] = t2;

    if (board[x][y] != 0) {
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    else {
        board[x][y] = dice[6];
    }
    cout << dice[1] << '\n';
}


void    south(int x, int y)
{
    int t1, t2, t5, t6;
    t1 = dice[1];
    t2 = dice[2];
    t5 = dice[5];
    t6 = dice[6];

    dice[1] = t2;
    dice[2] = t6;
    dice[5] = t1;
    dice[6] = t5;
    if (board[x][y] != 0) {
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    else {
        board[x][y] = dice[6];
    }
    cout << dice[1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> x >> y >> c;

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            cin >> board[i][j];

    for (int i = 0; i < c; i++)
        cin >> coms[i];

    
    for (int i = 0; i < c; i++) {
        if (coms[i] == 1) {
            y += 1;
            if (y < M)
                east(x, y);
            else
                y -= 1;
        }
        else if (coms[i] == 2) {
            y -= 1;
            if (y >= 0)
                west(x, y);
            else
                y += 1;
        }
        else if (coms[i] == 3) {
            x -= 1;
            if (x >= 0)
                north(x, y);
            else 
                x += 1;
        }
        else {
            x += 1;
            if (x < N)
                south(x, y);
            else 
                x -= 1;
        }
    }

    return 0;
}