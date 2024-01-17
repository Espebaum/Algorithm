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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int cnt = 0;
    for (int i = 666;;i++) {
        int tmp = i;
        while (tmp >= 666) {
            if (tmp % 1000 == 666) {
                cnt++;
                break ;
            }
            tmp /= 10;
        }
        if (cnt == N) {
            cout << i;
            break ;
        }
    }

    return 0;
}