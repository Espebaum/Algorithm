#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  (x).begin(), (x).end()
#define rep(i,a,b)    for(int i=(a);i<(b);++i)
#define sz(x)   (int)(x).size()
using namespace std;

int n, m; //4 2
int arr[10];
int num[10];

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout<<num[arr[i]]<<' ';
    cout<<'\n';
    return;
    }

    int s = 0;
    if (k != 0)s = arr[k-1];

    for (int i = s; i < n; i++)
    {
        arr[k] = i;
        solve(k+1);  
    }
}    

int main()
{   
    ios::sync_with_stdio(0);cin.tie(0);
    // int tc; cin>>tc;
    // while(tc--)

    cin>>n>>m;
    rep(i, 0, n)
    {
        cin>>num[i];
    }
    sort(num, num + n);
        solve(0);

    return 0;
}
