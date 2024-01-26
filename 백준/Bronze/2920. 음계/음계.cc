// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  x.begin(), x.end()
#define rep(i, a, b)    for(int i=(a);i<(b);++i)
using namespace std;

void solve() {
    vector<int> a(8), b, c;
    rep(i, 0, 8)cin>>a[i];
    c=b=a;
    sort(all(b));
    sort(all(c));
    reverse(all(c));
    if(a==b)cout<<"ascending";
    else if(a==c)cout<<"descending";
    else cout<<"mixed";
}

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    // int tc; cin>>tc;
    // while(tc--)
        solve();

    return 0;
}
