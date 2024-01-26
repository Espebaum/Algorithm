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

int N, M;
int arr[10];
int isused[10];

void    solve(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= N; i++) {
        arr[k] = i;
        solve(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    solve(0);
    return 0;
}