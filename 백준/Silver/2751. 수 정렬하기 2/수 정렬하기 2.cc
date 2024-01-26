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
    int n;cin>>n;
    vector<int>a(n);
    rep(i, 0, n)cin>>a[i];
    sort(all(a));
    rep(i, 0, n)cout<<a[i]<<'\n';
    // for(auto x : a)cout<<x<<'\n';

}

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    // int tc; cin>>tc;
    // while(tc--)
        solve();

    return 0;
}
