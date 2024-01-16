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

int M;
int board[2][3];
int ans;

void    solve(int n, int m, int c, int days, int sum)
{
    int point = board[n][m];
    if (c == m) {
        point /= 2;
    }

    sum += point;
    int col = m;
    days -= 1;
    
    if (days == 0) {
        if (sum >= M) {
            ans++;
        }
        return ;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            solve(i, j, col, days, sum);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int days;
    cin >> days;
    cin >> M;
    int sum = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            solve(i, j, -1, days, sum);
        }
    }

    cout << ans;

    return 0;
}