#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

long long sum;

void    solve(char c, int k)
{
    if (48 <= (int) c && (int) c <= 57) {
        sum += (c - 48) * pow(16, k);
    }
    else if (65 <= (int) c && (int) c <= 70) {
        sum += (c - 'A' + 10) * pow(16, k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    for (int i = 0; i < s.length(); i++)
    {
        solve(s[i], i);
    }
    cout << sum;
    return 0;
}