// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <stack>
#include <utility>
// #include <queue>
// #include <deque>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
#define x first
#define y second
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
    int n;cin>>n;
    stack<pii> st;
    rep(i, 0, n){
        int x;cin>>x;
        while(st.size() && st.top().x <= x)
            st.pop();
        if(st.empty()){
            cout<<'0'<<' ';
        }
        else{
            cout<<st.top().y<<' ';
        }
        st.push(pii(x, i + 1));
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
