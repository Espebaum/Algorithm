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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int     N;
int     tmp;
string  s;

void    solve(int start, int len)
{
    if (len - start == 1)
        return ;

    double first = (len - start) / 3;
    double second = (len - start) / 3 * 2;
    first += start;
    second += start;

    if ((int) first != first || (int) second != second)
        return ;

    for (int i = first; i < second; i++)
        s[i] = ' ';

    solve(start, first);
    solve(second, len);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> N)
    {
        s = "";

        int len = pow(3, N);
        tmp = len;
        for (int i = 0; i < len; i++)
            s.push_back('-');

        solve(0, len);

        cout << s << '\n';
    }

    return 0;
}