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

ll N, M;
ll arr[101010];
ll mn = __LONG_LONG_MAX__;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr,arr+N);
    int en = 0;
    for (int st = 0; st < N; st++) 
    {
        while (en < N && arr[en] - arr[st] < M)
            en++;
        if (en == N)
            break ;
        mn = min(mn, arr[en] - arr[st]);        
    }
    cout << mn;
    return 0;
}