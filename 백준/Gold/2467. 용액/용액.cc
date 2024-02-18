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
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
ll arr[101010];
ll mn = __LONG_LONG_MAX__;
ll ans1, ans2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    int l = 0; int r = N - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (abs(sum) < abs(mn)) {
            mn = abs(sum);
            ans1 = arr[l];
            ans2 = arr[r];
        }
        if (sum == 0)
            break ;
        if (sum > 0)
            r--;
        else
            l++;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}