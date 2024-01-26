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

int K;
int arr[10];
int isused[10];
int num[10];

void    solve(int k)
{
    if (k == 6) {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ; 
    }

    for (int i = 0; i < K; i++) {
        if (!isused[i]) {
            arr[k] = num[i];
            if (k > 0 && arr[k - 1] > arr[k])
                continue; 
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1)
    {
        cin >> K;
        if (K == 0)
            break ;
        for (int i = 0; i < K; i++) {
            int t; cin >> t;
            num[i] = t;
        }

        solve(0);
        cout << '\n';

        for (int i = 0; i < 10; i++) {
            arr[i] = 0;
            num[i] = 0;
        }
    }

    return 0;
}