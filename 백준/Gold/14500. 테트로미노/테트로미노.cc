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
using namespace std;

int board[505][505];
int N, M;
vector<int> ans;

void    solve1()
{
    int mx = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M - 3; j++) {
            int sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
            mx = max(mx, sum);
        }
    } // ㅡ
    for (int i = 1; i <= N - 3; i++) {
        for (int j = 1; j <= M; j++) {
            int sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
            mx = max(mx, sum);
        }
    } // ㅣ
    ans.push_back(mx);
}

void    solve2()
{
    int mx = -1;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= M - 1; j++) {
            int sum = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
            mx = max(mx, sum);
        }
    }
    ans.push_back(mx);
}

void    solve3()
{
    int mx = -1;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= M - 2; j++) {
            int sum1 = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
            int sum2 = board[i][j] + board[i + 1][j] + board[i + 1][j + 1]+ board[i + 1][j + 2];
            int sum3 = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i][j + 2];
            int sum4 = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
            mx = max(mx, sum1); mx = max(mx, sum2); mx = max(mx, sum3); mx = max(mx, sum4);
        }
    } // 가로 ㄴㄱ
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= M - 1; j++) {
            int sum1 = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j];
            int sum2 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j];
            int sum3 = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
            int sum4 = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
            mx = max(mx, sum1); mx = max(mx, sum2); mx = max(mx, sum3); mx = max(mx, sum4);
        }
    } // 세로 ㄴㄱ
    ans.push_back(mx);
}

void    solve4()
{
    int mx = -1;
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= M - 1; j++) {
            int sum1 = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
            int sum2 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j] + board[i + 2][j];
            mx = max(mx, sum1); mx = max(mx, sum2);
        }
    }
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= M - 2; j++) {
            int sum1 = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
            int sum2 = board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2];
            mx = max(mx, sum1); mx = max(mx, sum2);
        }
    }
    ans.push_back(mx);
}

void    solve5()
{
    int mx = -1;
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= M - 1; j++) {
            int sum1 = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j];
            int sum2 = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
            mx = max(mx, sum1); mx = max(mx, sum2);
        }
    } // 
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= M - 2; j++) {
            int sum1 = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
            int sum2 = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
            mx = max(mx, sum1); mx = max(mx, sum2);
        }
    }
    ans.push_back(mx);
}

int main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    }

    solve1();
    solve2();
    solve3();
    solve4();
    solve5();

    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << ' ';
    // }
    cout << *max_element(ans.begin(), ans.end());

    return 0;
}