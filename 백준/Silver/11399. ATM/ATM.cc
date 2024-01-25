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
int arr[1010];
int dp[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    int sum = 0;
    
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        sum += dp[i];
    }
    cout << sum;
    return 0;
}