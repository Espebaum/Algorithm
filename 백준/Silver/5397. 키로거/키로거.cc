// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
// #include <queue>
// #include <deque>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
using namespace std;
using vi = vector<int>;

void solve() {
    string raw;
    cin>>raw;
    
    list<char> a;
    auto cur = a.end();
    for(auto c:raw){
        if(c == '<'){
            if(cur != a.begin()) cur--;
        }
        else if(c == '>'){
            if(cur != a.end()) cur++;
        }
        else if(c == '-'){
            if(cur != a.begin())
                cur = a.erase(--cur);
        }
        else{
            a.insert(cur, c);
        }
    }
    for (auto c:a){
        cout<<c;
    }
    cout<<'\n';
}


int main()
{   
    ios::sync_with_stdio(0);cin.tie(0);

    int tc; cin>>tc;
    while(tc--)
        solve();
    return 0;
}
