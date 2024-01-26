#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int arr[2000000] = {0, };
int n; // 1<=n<=100000
int x; // 1<=x<=2000000
int res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; // 9;

    int keys[n];
    fill (keys, keys + n, 0);

    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        if (x > keys[i]) {
            if (arr[x - keys[i]]) 
                res++;
        }
        arr[keys[i]]++;
    }
    cout << res << endl;
    return 0;
}