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
#include <climits>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
int arr[100010];
int dp[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
    }

    cout << *max_element(dp + 1, dp+N+1);
    return 0;
}