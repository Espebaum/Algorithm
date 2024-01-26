// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  (x).begin(), (x).end()
#define rep(i, a, b) for(int i=(a);i<(b);++i)
using namespace std;

int n, m;
int arr[1030][1030];
int psum[1030][1030];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    rep(i,1,n+1)rep(j,1,n+1)
        cin>>arr[i][j];
    rep(i,1,n+1)rep(j,1,n+1)
        psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    while (m--)
    {
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<psum[r2][c2] - psum[r2][c1 - 1] - psum[r1 - 1][c2] + psum[r1 - 1][c1 - 1]<<'\n';   
    }
    return 0;
}