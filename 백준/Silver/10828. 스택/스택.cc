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
    while(n--){
        string cmd;cin>>cmd;
        if(cmd == "push"){
            int x;cin>>x;
            a.push(x);
        }
        else if(cmd == "pop"){
            if(a.empty())
                cout<<-1<<'\n';
            else{
                cout<<a.top()<<'\n';
                a.pop();
            }
        }
        else if(cmd == "size"){
            cout<<a.size()<<'\n';
        }
        else if(cmd == "empty"){
            if(a.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
        else if(cmd == "top"){
            if(a.empty())
                cout<<-1<<'\n';
            else
                cout<<a.top()<<'\n';
        }
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
