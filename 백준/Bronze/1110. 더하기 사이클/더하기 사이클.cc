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

int start;
int sum;

void    solve(int k)
{
    int ten = k / 10;
    int one = k % 10;
    int my = ten + one;
    if (my >= 10)
        my = my % 10;
    int go = one * 10 + my;
    sum++;
    if (go == start) {
        cout << sum;
        return ;
    } else {
        solve(go);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    start = N;
    solve(N);
    return 0;
}