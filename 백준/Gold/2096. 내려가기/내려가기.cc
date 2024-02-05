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
int board[100010][4];
// int dpmx[100010][4];
// int dpmn[100010][4];
int rdpmx[3][4];
int rdpmn[3][4];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++)
            cin >> board[i][j];
    }
    
    rdpmx[1][1] = rdpmn[1][1] = board[1][1];
    rdpmx[1][2] = rdpmn[1][2] = board[1][2];
    rdpmx[1][3] = rdpmn[1][3] = board[1][3];

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            int k = 2;
            rdpmx[k][1] = max(rdpmx[1][1] + board[i][1], rdpmx[1][2] + board[i][1]);
            rdpmx[k][2] = max(rdpmx[1][1] + board[i][2], rdpmx[1][2] + board[i][2]);
            rdpmx[k][2] = max(rdpmx[k][2], rdpmx[1][3] + board[i][2]);
            rdpmx[k][3] = max(rdpmx[1][2] + board[i][3], rdpmx[1][3] + board[i][3]);
        } else {
            int k = 1;
            rdpmx[k][1] = max(rdpmx[2][1] + board[i][1], rdpmx[2][2] + board[i][1]);
            rdpmx[k][2] = max(rdpmx[2][1] + board[i][2], rdpmx[2][2] + board[i][2]);
            rdpmx[k][2] = max(rdpmx[k][2], rdpmx[2][3] + board[i][2]);
            rdpmx[k][3] = max(rdpmx[2][2] + board[i][3], rdpmx[2][3] + board[i][3]);
        }
    }
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            int k = 2;
            rdpmn[k][1] = min(rdpmn[1][1] + board[i][1], rdpmn[1][2] + board[i][1]);
            rdpmn[k][2] = min(rdpmn[1][1] + board[i][2], rdpmn[1][2] + board[i][2]);
            rdpmn[k][2] = min(rdpmn[k][2], rdpmn[1][3] + board[i][2]);
            rdpmn[k][3] = min(rdpmn[1][2] + board[i][3], rdpmn[1][3] + board[i][3]);
        } else {
            int k = 1;
            rdpmn[k][1] = min(rdpmn[2][1] + board[i][1], rdpmn[2][2] + board[i][1]);
            rdpmn[k][2] = min(rdpmn[2][1] + board[i][2], rdpmn[2][2] + board[i][2]);
            rdpmn[k][2] = min(rdpmn[k][2], rdpmn[2][3] + board[i][2]);
            rdpmn[k][3] = min(rdpmn[2][2] + board[i][3], rdpmn[2][3] + board[i][3]);
        }
    }
    int mx, mn;
    if (N % 2 == 0) {
        mx = max(rdpmx[2][1], rdpmx[2][2]);
        mx = max(mx, rdpmx[2][3]);
    } else {
        mx = max(rdpmx[1][1], rdpmx[1][2]);
        mx = max(mx, rdpmx[1][3]);
    }
    if (N % 2 == 0) {
        mn = min(rdpmn[2][1], rdpmn[2][2]);
        mn = min(mn, rdpmn[2][3]);
    } else {
        mn = min(rdpmn[1][1], rdpmn[1][2]);
        mn = min(mn, rdpmn[1][3]);
    }
    cout << mx << ' ' << mn;

    return 0;
}