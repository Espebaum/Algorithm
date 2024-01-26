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

int A, B, C;

long long   ppow(long long a, long long b, long long m)
{
    if (b == 1)
        return (a % m);
    long long val = ppow(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0)
        return val;
    return val * a % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    cout << ppow(A, B, C);
    return 0;
}