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

int N, M, ans;
int broken[10];

int fp()
{
    int pnum;
    for (int i = N;;i++) {
        int j;
        string s = to_string(i);
        for (j = 0; j < s.length(); j++) {
            if (broken[s[j] - 48] == 1)
                break ;
        }
        if (j == s.length()) {
            return i;
        }
    }
    return -2147483648;
}

int fm()
{
    int mnum;
    for (int i = N;i>=0;i--) {
        int j;
        string s = to_string(i);
        for (j = 0; j < s.length(); j++) {
            if (broken[s[j] - 48] == 1)
                break ;
        }
        if (j == s.length()) {
            return i;
        }
    }
    return 2147483647;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int cur = 100;
    int allBroken = 0;
    int pBroken = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        broken[num]++;
    }
    if (broken[0] == 1 && broken[1] == 1 && broken[2] == 1 && broken[3] == 1 && broken[4] == 1 && broken[5] == 1 && broken[6] == 1 && broken[7] == 1 && broken[8] == 1 && broken[9] == 1)
        allBroken = 1;
    if (broken[1] == 1 && broken[2] == 1 && broken[3] == 1 && broken[4] == 1 && broken[5] == 1 && broken[6] == 1 && broken[7] == 1 && broken[8] == 1 && broken[9] == 1)
        pBroken = 1;

    if (allBroken == 1) {
        cout << abs(cur - N); return 0;
    }

    int res;
    int m = fm();
    if (pBroken == 0) {
    int p = fp();
        if (abs(N - p) < abs(N - m))
            res = p;
        else
            res = m;
    } else {
        res = m;
    }
    // cout << "Res: " <<res <<'\n';
    string s = to_string(res);
    ans += s.length();
    ans += abs(N - res);

    cout << min(ans, abs(cur - N));
    return 0;
}