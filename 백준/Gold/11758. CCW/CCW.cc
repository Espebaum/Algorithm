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

int xa, ya, xb, yb, xc, yc;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    ans = (xa*yb+xb*yc+xc*ya) - (xb*ya+xc*yb+xa*yc);
    if (ans > 0) cout << 1;
    else if (ans == 0) cout << 0;
    else cout << -1;
    return 0;
}