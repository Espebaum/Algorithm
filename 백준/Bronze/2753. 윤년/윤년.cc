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
    int y;
    cin>>y;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        cout<<1;
    else
        cout<<0;
}   

int main(void)
{   
    ios::sync_with_stdio(0);cin.tie(0);
    solve();

    return (0);
}
