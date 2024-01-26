#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, cur;

int recursion(const string& s, int left, int right)
{
    cur++;
    if (left >= right)
        return 1;
    else if (s[left] != s[right])
        return 0;
    else
        return (recursion(s, left+1, right-1));
}

void    isPalindrome(string s)
{
    cout << recursion(s, 0, s.length() - 1) << ' ' << cur << '\n';
}

void    solve()
{
    string  s;
    cin >> s;
    cur = 0;
    isPalindrome(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while (N--)
        solve();

    return 0;
}