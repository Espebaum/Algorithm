// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  x.begin(), x.end()
using namespace std;

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    for (int i = 1; i < 10; i++)
    {
        cout<<n<<" * "<<i<<" = "<<n*i<<'\n';
    }

    return 0;
}
