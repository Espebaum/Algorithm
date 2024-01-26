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

int N;
int dp[1010];
int arr[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for (int i = 2; i <= N; i++)
    {
        int mx = -1;
        for (int k = 1; k < i; k++) {
            if (arr[k] < arr[i]) {
                mx = max(mx, dp[k]);
            }
        }
        if (mx != -1)
            dp[i] = mx + arr[i];
        else
            dp[i] = arr[i];
    }
    cout << *max_element(dp + 1, dp + N + 1);
    
    return 0;
}