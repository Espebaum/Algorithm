// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <stack>
// #include <queue>
// #include <deque>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
using namespace std;
using vi = vector<int>;

void solve() {
    int n;cin>>n;
    stack<int> a;
    vector<char> ans;
    int cur = 1;

    rep(i, 0, n){
        int x;cin>>x;
        rep(i, cur, x+1){
            ans.push_back('+');
            a.push(cur);
            cur++;
        }
        if(a.top() != x){
            cout<<"NO";
            return;
        }
        else{
            ans.push_back('-');
            a.pop();
        }
    }
    for(auto x:ans){
        cout<<x<<'\n';
    }
}


int main()  
{   
    ios::sync_with_stdio(0);cin.tie(0);

    //int tc; cin>>tc;
    //while(tc--)
        solve();
    return 0;
}
