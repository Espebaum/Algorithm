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

int N, M, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int r = 1;
    while ((N % 2 == 1) && (M % 2 == 1))
    {
        C += r;
        N /= 2;
        M /= 2;
        r *= 4;
    }
    cout << C;
    return 0;
}