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
    int n;string s;
    cin>>n>>s;
    for (auto c : s)
    {
        for (int i = 0; i < n; i++)
        {
            cout<<c;
        }
    }
    cout<<'\n';
}

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    int tc; cin>>tc;
    while(tc--)
        solve();

    return 0;
}
