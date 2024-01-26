#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

string  s;
int    board[27];

void    count()
{
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            board[s[i] - 'a']++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (getline(cin, s))
    {
        count();
    }

    int mx = 0;
    for (int i = 0; i < 27; i++) {
        mx = max(mx, board[i]);
    }

    for (int i = 0; i < 27; i++) {
        if (board[i] == mx)
            cout << (char)(i + 'a');
    }

    return 0;
}