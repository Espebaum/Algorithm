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
#include <cmath>
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int board[11][11];
bool en;

bool checkIdx(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == n) 
            return false;   
    }
    for (int i = 0; i < 9; i++) {
        if (board[i][y] == n) 
            return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(x/3)*3 + i][(y/3)*3 + j] == n)
                return false;
        }
    }
    return true;
}

void    check(int x, int y)
{
    if (y > 8) 
        check(x + 1, y - 9);
    if (x > 8 || en) {
        en = 1;
        return ;
    }
    if (board[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (checkIdx(x, y, i)) {
                board[x][y] = i;
                check(x, y + 1);
                if (en) return;
                board[x][y] = 0;
            }
        }
    } 
    else 
        check(x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        string s; cin >> s;

        for (int j = 0; j < 9; j++) {
            board[i][j] = (int)s[j] - '0';
        }
    }
    check(0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}