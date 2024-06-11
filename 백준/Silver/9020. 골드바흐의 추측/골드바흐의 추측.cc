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
#include <climits>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int     N, num;
bool    p[10101];

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;

    fill(p, p+10101, true);
    for (int i = 2; i < 10101; i++) {
        if (p[i]) {
            for (int k = i * i; k <= 10101; k += i)
                p[k] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int mn = INT_MAX;
        cin >> num;
        int half = (num / 2);
        int f, s;
        for (int k = 2; k <= half; k++) {
            int first = k;
            int second = num - first;
            if (p[first] && p[second]) {
                mn = min(mn, second - first);
                f = first; s = second;
            }
        }
        cout << f << ' ' << s << '\n';
    }

    return 0;
}