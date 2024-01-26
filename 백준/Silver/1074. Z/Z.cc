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

int solve(int N, int r, int c)
{
    if (N == 0)
        return 0;

    int half = pow(2, N - 1);

    if (r < half && c < half)
        return solve(N - 1, r, c);
    else if (r < half && c >= half)
        return half * half + solve(N - 1, r, c - half);
    else if (r >= half && c < half)
        return half * half * 2 + solve(N - 1, r - half, c);
    return half * half * 3 + solve(N - 1, r - half, c - half);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, r, c;
    cin >> N >> r >> c;

    cout << solve(N, r, c);

    return 0;
}