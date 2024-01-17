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
#include <sstream>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef unsigned long long llu;
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    int sum = 0;

    for (int i = 2; i <= N; i++) {
        int tmp = i;
        while (tmp % 5 == 0) {
            tmp /= 5;
            sum++;
        }
    }
    cout << sum;
    return 0;
}