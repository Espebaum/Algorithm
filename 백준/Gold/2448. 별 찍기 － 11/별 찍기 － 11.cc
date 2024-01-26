#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
char    board[3100][6200];


void    func(int x, int y, int N)
{
    if (N == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for (int j = y - 2; j <= y + 2; j++)
            board[x + 2][j] = '*';
        return;
    }

    func(x, y, N / 2);
    func(x + N / 2, y - N / 2, N / 2);
    func(x + N / 2, y + N / 2, N / 2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N * 2; j++)
            board[i][j] = ' ';

    func(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2 - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}