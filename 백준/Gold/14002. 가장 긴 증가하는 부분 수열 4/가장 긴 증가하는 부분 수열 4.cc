#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int arr[1010];
int dp[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1] = 1;

    for (int i = 2; i <= N; i++) 
    {
        int mx = -1;
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                mx = max(mx, dp[j]);
        if (mx != -1)
            dp[i] = mx + 1;
        else
            dp[i] = 1;
    }

    int val = -1;
    for (int i = 1; i <= N; i++)
        val = max(val, dp[i]);

    cout << val << '\n';
    vector<int>ans;
    for (int i = N; i >= 1; i--) {
        if (dp[i] == val) 
        {
            if (ans.empty()) 
                ans.push_back(arr[i]);
            else if (!ans.empty()) 
            {
                if (dp[i] > ans[ans.size() - 1])
                    continue ;
                else
                    ans.push_back(arr[i]);
            }
            val -= 1;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}