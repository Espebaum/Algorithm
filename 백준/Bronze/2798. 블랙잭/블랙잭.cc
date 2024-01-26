// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  (x).begin(), (x).end()
#define rep(i, a, b)    for(int i=(a);i<(b);++i)
#define sz(x)   (int)(x).size()
using namespace std;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n);
    rep(i, 0, n)cin>>a[i];
    int ans = 0;
    rep(i, 0, n)rep(j, i+1, n)rep(k, j+1, n){
        int tmp_ans = a[i]+a[j]+a[k];
        if (tmp_ans <= m)
            ans = max(ans, tmp_ans);
    }
    cout<<ans;

}

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    // int tc; cin>>tc;
    // while(tc--)
        solve();

    return 0;
}
