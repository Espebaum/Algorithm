// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
// #include <string>
// #include <queue>
// #include <deque>
#define all(x)  (x).begin(), (x).end()
#define rep(i,a,b)    for(int i=(a);i<(b);++i)
#define sz(x)   (int)(x).size()
using namespace std;
using vi = vector<int>;

void solve()
{
    vi a(3);
    rep(i, 0, 3)cin>>a[i];
    sort(all(a));
    rep(i, 0, 3)cout<<a[i]<<' ';
}   

int main(void)
{   
    ios::sync_with_stdio(0);cin.tie(0);
    solve();

    return (0);
}
