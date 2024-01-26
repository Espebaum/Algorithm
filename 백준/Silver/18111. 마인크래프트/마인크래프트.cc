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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, M;
long long B;
int board[505][505];
int ans;
int mn = 2147483647;  
int mx = 0;

// 인벤토리에 넣기 -> 2초
// 인벤토리에서 꺼내서 놓기 -> 1초
int solve(int k)
{
    long long save = B;
    int time = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > k) {
                time += 2 * (board[i][j] - k);
                save += board[i][j] - k;
            } else if (board[i][j] < k) {
                time += k - board[i][j];
                save -= k - board[i][j];
            }
        }
    }
    if (save < 0)
        return 2147483647;
    return time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            mn = min(mn, board[i][j]);
            mx = max(mx, board[i][j]);
        }
    }

    vector< pair<int, int> > v;

    for (int i = 0; i <= 256; i++) {
        v.push_back(make_pair(solve(i), i));
    }
    sort(v.begin(), v.end());

    int minTime = v[0].first;
    int temp = -1;
    int maxheight = 0;
    int idx = 0;
    int i = 0;

    while (v[i].first == minTime) {
        temp = maxheight;
        maxheight = max(maxheight, v[i].second);
        if (temp != maxheight)
            idx = i;
        i++;
    }

    cout << v[idx].first << ' ' << v[idx].second << '\n';

    return 0;
}