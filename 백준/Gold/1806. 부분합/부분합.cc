#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, S;
int arr[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>S;
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    
    int en = 0;
    int total = arr[0];
    int mn = INF;
    for (int st = 0; st < N; st++) {
        total -= arr[st - 1];
        while (en < N && total < S) {
            en++;
            total += arr[en];
        }
        if (en == N)
            break ;
        // cout << "st: " << st << " en: " << en << '\n';
        mn = min(mn, en - st + 1);
    }
    if (mn == INF)
        mn = 0;
    cout << mn;
    return 0;
}