#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
vector<pair<double,double>>vp;

void    check()
{
    double first = 0;
    for (int i = 0; i < N; i++) {
        if (i+1 == N)
            first += (double)vp[i].first*vp[0].second;
        else
            first += (double)vp[i].first*vp[i+1].second;
    }
    double second = 0;
    for (int i = 0; i < N; i++) {
        if (i+1 == N)
            second += (double)vp[0].first*vp[i].second;
        else
            second += (double)vp[i+1].first*vp[i].second;
    }
    double res = abs(first - second) * 0.5;
    cout << fixed << setprecision(1) << res; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double x,y; cin>>x>>y;
        vp.push_back({x,y});
    } 
    check();
    return 0;
}