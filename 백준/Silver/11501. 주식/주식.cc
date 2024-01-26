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
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int T, N;
int arr[1000010];

long long   solve()
{
    long long stock = 0;
    long long sum = 0;
    long long check = 0;
    for (int i = N; i >= 2; i--) {
        check = arr[i];
        // cout << "check: " << check << '\n';
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < check) {
                // cout << "buy\n";
                stock += 1;
                sum -= arr[j];
                // cout << "money after buy: " << sum << '\n';
            } else
                break ;
        }
        // cout << "sell\n";
        sum += stock * check;
        i -= stock;
        stock = 0;
        // cout << "money after sell: " << sum << '\n';
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cout << solve() << "\n";
    }
    return 0;
}