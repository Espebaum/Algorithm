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

int     N;
char    board[2200][2200];


void    func(int x, int y, int N)
{
    if (N == 1) {
        board[x][y] = '*';
        return ;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;
            func(x + (i * N) / 3, y + (j * N) / 3, N / 3);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
        fill(board[i], board[i] + N, ' ');

    func(0, 0, N);
    for (int i = 0; i < N; i++)
        cout << board[i] << '\n';

    return 0;
}