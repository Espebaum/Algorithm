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
    vector<int> a(9);
    for (int i = 0; i < 9; i++)cin>>a[i];
    int ans = *max_element(all(a));
    int ans_idx = max_element(all(a)) - a.begin();
    cout<<ans<<'\n'<<ans_idx+1;
}

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    // int tc; cin>>tc;
    // while(tc--)
        solve();

    return 0;
}
