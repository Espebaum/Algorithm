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

    int a, b;
    cin>>a>>b;

    cout<<(a>b ? ">" : (a<b ? "<" : "=="));

    return 0;
}
