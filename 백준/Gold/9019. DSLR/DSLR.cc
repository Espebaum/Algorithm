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

int N;
// int    vis[20002];
string  visW[20010];
int start, en; 

int l_rotate(int k)
{
    int left_one = k / 1000;
    int right_three = k % 1000;
    return right_three * 10 + left_one;
}

int r_rotate(int k)
{
    int right_one = k % 10;
    int left_three = k / 10;
    return right_one * 1000 + left_three;
}

void    solve()
{
    queue<int> q;
    q.push(start);
    visW[start] = "G";
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        // cout << "cur: " << cur << '\n';
        if (cur == en) {
            // cout << "checked: ";
            string ans(visW[cur].begin() + 1, visW[cur].end());
            cout << ans << '\n';
            return ;
        }
        for (int i = 1; i <= 4; i++) {
            int ncur;
            if (i == 1) {
                ncur = cur * 2;
                if (ncur > 9999) {
                    ncur %= 10000;
                }
            } else if (i == 2) {
                ncur = cur - 1;
                if (ncur == -1)
                    ncur = 9999;
            } else if (i == 3) {
                ncur = l_rotate(cur);
            } else {
                ncur = r_rotate(cur);
            }
            if (visW[ncur] != "")
                continue;
            string newWord = visW[cur];
            if (i == 1) {
                newWord.push_back('D');
                visW[ncur] = newWord;
            } else if (i == 2) {
                newWord.push_back('S');
                visW[ncur] = newWord;
            } else if (i == 3) {
                newWord.push_back('L');
                visW[ncur] = newWord;
            } else {
                newWord.push_back('R');
                visW[ncur] = newWord;
            }
            // vis[ncur] = 1;
            q.push(ncur);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while (N--) {
        cin >> start >> en;
        solve();
        // fill(vis, vis+20002, 0);
        for (int i = 0; i < 20002; i++)
            visW[i] = "";
    }
    // cout << l_rotate(789) << '\n'; // 7890
    // cout << l_rotate(1) << '\n'; // 10
    // cout << l_rotate(10) << '\n'; // 100
    // cout << l_rotate(100) << '\n'; // 1000
    // cout << l_rotate(1000) << '\n'; // 1
    // cout << r_rotate(789) << '\n'; // 9078
    // cout << r_rotate(1) << '\n'; // 1000
    // cout << r_rotate(10) << '\n'; // 1
    // cout << r_rotate(100) << '\n'; // 10
    // cout << r_rotate(1000) << '\n'; // 100
    return 0;
}