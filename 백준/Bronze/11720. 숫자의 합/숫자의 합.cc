// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  x.begin(), x.end()
using namespace std;

void solve() {
    int n; cin>>n;
    int ans = 0;
    string s; cin>>s;
    for (auto c : s)
    {
        ans += c - '0';
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
