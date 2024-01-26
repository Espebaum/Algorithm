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

int col[15];
int N, sum;

bool    check(int m)
{
    for (int i = 0; i < m; i++) {
        if (col[i] == col[m] || abs(col[i] - col[m]) == abs(i - m))
            return false;
    }
    return true;
}

void    func(int m)
{
    if (m == N) {
        sum++;
    }
    else {
        for (int i = 0; i < N; i++)
        {
            col[m] = i;
            if (check(m))
                func(m + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    func(0);
    cout << sum;

    return 0;
}