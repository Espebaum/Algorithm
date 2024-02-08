#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
int arr[1010];
int dp1[1010];
int dp2[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        int mx = -1;
        for (int k = 1; k < i; k++) {
            if (arr[k] < arr[i])
                mx = max(mx, dp1[k]);
        }
        if (mx == -1)
            dp1[i] = 1;
        else
            dp1[i] = mx + 1;
    }

    // for (int i = 1; i <= N; i++)
    //     cout << dp1[i] << ' ';
    // cout <<'\n';

    reverse(arr+1, arr+N+1);

    for (int i = 1; i <= N; i++) {
        int mx = -1;
        for (int k = 1; k < i; k++) {
            if (arr[k] < arr[i])
                mx = max(mx, dp2[k]);
        }
        if (mx == -1)
            dp2[i] = 1;
        else
            dp2[i] = mx + 1;
    }

    reverse(dp2+1,dp2+1+N);

    // for (int i = 1; i <= N; i++)
    //     cout << dp2[i] << ' ';
    // cout <<'\n';

    vector<int>ans;
    for (int i = 0; i < N; i++) {
        ans.push_back(dp1[i+1]+dp2[i+1]);
    }
    cout << *max_element(ans.begin(), ans.end()) - 1;
    return 0;
}