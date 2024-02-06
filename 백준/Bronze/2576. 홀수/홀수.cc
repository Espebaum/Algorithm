#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <climits>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int sum = 0;
    int mn = INT_MAX;
    for (int i = 0; i < 7; i++)
    {
        int number; cin >> number;
        if (number % 2) {
            sum += number;
            mn = min(mn, number);
        }
    }
    if (sum != 0) {
        cout << sum << '\n' << mn;
    }
    else
        cout << -1;
    return 0;
}