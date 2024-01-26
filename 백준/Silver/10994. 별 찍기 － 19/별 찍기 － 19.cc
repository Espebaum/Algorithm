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
char board[404][404];

void    draw(int len, int row, int col)
{
    for (int i = 0; i < len; i++)
    {
        if (i == 0 || i == len - 1) {
            for (int j = 0; j < len; j++)
                board[row + i][col + j] = '*';
        }
        else
        {
            board[row + i][col] = '*';
            board[row + i][col + len - 1] = '*';
        }
    }
}

void    solve(int n, int row, int col)
{
    int len = 1 + 4 * (n - 1);

    draw(len, row, col);

    if (n == 1) {
        return ;
    }

    solve(n - 1, row + 2, col + 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int num = 1 + 4 * (N - 1);
        
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            board[i][j] = ' ';

    solve(N, 0, 0);

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}