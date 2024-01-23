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

int T, N;

int getDist(string a, string b, string c)
{
    int dist = 0;
    for (int i = 0; i < a.size(); i++) {
        dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
    }
    return dist;
}

int solve(int n, vector<string> m)
{
    if (n > 32)
        return 0;
    
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ans = min(ans, getDist(m[i], m[j], m[k]));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<string>  m(N);
        for (int i = 0; i < N; i++) {
            cin >> m[i];
        }
        cout << solve(N, m) << '\n';
    }

    return 0;
}