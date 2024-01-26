// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <iterator>
// #include <queue>
// #include <deque>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
using namespace std;
using vi = vector<int>;

void solve() {
    int a, b;cin>>a>>b;
    vi ans;

    list<int> c;
    for(int i = 1;i <= a; ++i){
        c.push_back(i);
    }
    auto cur = prev(c.end());
    while(a--){
        rep(i, 0, b){
            cur++;
            if(cur == c.end())
                cur = c.begin();
        }
        ans.push_back(*cur);
        cur = prev(c.erase(cur));
    }

    cout<<'<';
    rep(i, 0, sz(ans)) {
        cout<<ans[i];
        if(i != sz(ans)-1)
            cout<<", ";
    }
    cout<<'>';
    //12345671234567
}


int main()
{   
    ios::sync_with_stdio(0);cin.tie(0);

    //int tc; cin>>tc;
    //while(tc--)
        solve();
    return 0;
}
