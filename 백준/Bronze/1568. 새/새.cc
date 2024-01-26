#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
int sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int i = 1;
    int turn = 0;

    while (1)
    {
        turn++;
        sum += i;
        i += 1;
        if (sum > N) {
            i -= 1;
            sum -= i;
            sum += 1;
            i = 2;
        }
        if (sum == N)
            break ;
    }
    cout << turn;
    return 0;
}