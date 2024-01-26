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

int N;

void    func(int a, int b, int n)
{
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return ;
    }
    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    cout << (1<<N) - 1 << '\n';
    func(1, 3, N);

    return 0;
}