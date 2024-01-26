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
int board[130][130];
int ans[2];

bool    check(int x, int y, int N)
{
    for (int i = x; i < x + N; i++)
        for (int j = y; j < y + N; j++)
            if (board[x][y] != board[i][j])
                return false;
    return true;
}

void    func(int x, int y, int N)
{
    if (check(x, y, N)) {
        ans[board[x][y]]++;
        return ;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            func(x + (i * N) / 2, y + (j * N) / 2, N / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    func(0, 0, N);
    for (int i = 0; i < 2; i++)
        cout << ans[i] << '\n';
    return 0;
}