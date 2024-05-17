#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).en()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

ll N;
ll arr[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr+1, arr+N+1);
    ll first, second, third;
    ll mn = LONG_MAX;
    
    // for (int i = 1; i <= N; i++) {
    //     cout << arr[i] << ' ';
    // }   cout << '\n';

    for (int i = 1; i <= N - 2; i++)
    {
        int st = i + 1;
        int en = N;
        while (st < en)
        {
            ll temp = mn;
            ll result = arr[i] + arr[st] + arr[en];
            mn = min(mn, abs(result));
            if (mn != temp) {
                temp = mn;
                first = arr[i];
                second = arr[st];
                third = arr[en];
            }
            if (result < 0) 
                st++;
            else
                en--;
        }
    }

    vector<int>ans;
    ans.push_back(first);
    ans.push_back(second);
    ans.push_back(third);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < 3; i++)
        cout << ans[i] << ' ';

    return 0;
}