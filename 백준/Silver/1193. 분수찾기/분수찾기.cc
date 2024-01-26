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

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int sum = 0;
    int i = 0;
    int ud = 0; // down

    while (1)
    {
        i += 1;
        sum += i;
        if ((i % 2) == 1) {
            ud = 1; // up
        }
        else if ((i % 2) == 0) {
            ud = 0; // down
        }
        if (sum >= N)
            break ;
    }

    int start = sum - i + 1;
    int first, second;

    if (ud == 1) {
        first = i;
        second = 1;
    } else {
        first = 1;
        second = i;
    }

    if (start == N) {
        cout << first << "/" << second;
        return 0;
    } else {
        if (ud == 1) {
            for (int i = 0; i < N - start; i++) {
                first -= 1;
                second += 1;
            }
        } else {
            for (int i = 0; i < N - start; i++) {
                first += 1;
                second -= 1;
            }
        }
    }
    cout << first << "/" << second;
    return 0;
}