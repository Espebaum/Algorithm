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

void solve(int k)
{
    if (m == k) 
    {  
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    int st = 1;
    if (k != 0)st = arr[k-1];

    for (int i = st; i <= n; i++)
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
        solve(0);

    return 0;
}
