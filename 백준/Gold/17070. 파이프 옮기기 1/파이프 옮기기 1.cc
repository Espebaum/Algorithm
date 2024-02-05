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

int N;
int board[20][20];
int ans;
// int state = 0; // 0가로, 1세로, 2대각선

void    solve(pair<int,int>cur, int state)
{
    int cx = cur.first;
    int cy = cur.second;
    if (cx > N || cy > N) {
        return ;
    }
    if (cx == N && cy == N) {
        ans++; 
        return ;
    }
    // --가로-- //
    if (state == 0) {
        if (board[cx][cy+1] != 1)
            solve({cx, cy+1}, 0);
        if (board[cx][cy+1] != 1 && board[cx+1][cy+1] != 1 && board[cx+1][cy] != 1)
            solve({cx+1, cy+1}, 2);
    }
    // --세로-- //
    if (state == 1) {
        if (board[cx+1][cy] != 1)
            solve({cx+1, cy}, 1);
        if (board[cx+1][cy] != 1 && board[cx+1][cy+1] != 1 && board[cx][cy+1] != 1)
            solve({cx+1,cy+1}, 2);
    }
    // --대각선-- //
    if (state == 2) {
        if (board[cx][cy+1] != 1)
            solve({cx, cy+1}, 0);
        if (board[cx+1][cy] != 1)
            solve({cx+1, cy}, 1);
        if (board[cx][cy+1] != 1 && board[cx+1][cy+1] != 1 && board[cx+1][cy] != 1)
            solve({cx+1, cy+1}, 2);
    }
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) 
            cin >> board[i][j];
    }
    pair<int,int>st = make_pair(1, 2);

    solve(st, 0);
    cout << ans;
    return 0;
}