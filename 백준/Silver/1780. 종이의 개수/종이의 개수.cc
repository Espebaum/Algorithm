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

int board[2200][2200];
int paper[3];

bool    check(int x, int y, int z)
{
    for (int i = x; i < x + z; i++)
        for (int j = y; j < y + z; j++)
            if (board[x][y] != board[i][j])
                return false;
    return true;
}

void    func(int x, int y, int N)
{
    if (check(x, y, N)) {
        paper[board[x][y] + 1] += 1;
        return ;
    }
    int z = N / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            func(x + (i * z), y + (j * z), z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    func(0, 0, N);

    for (int i = 0; i < 3; i++)
        cout << paper[i] << '\n';

    return 0;
}