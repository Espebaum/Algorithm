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
using namespace std;

int ti[20];
int pay[20];
int d[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> ti[i] >> pay[i];

    for (int i = N; i >= 1; i--) {
        if (i + ti[i] <= N + 1) {
            d[i] = max(d[i + ti[i]] + pay[i], d[i + 1]);
        }
        else d[i] = d[i + 1];
    }
    cout << *max_element(d, d + N + 1);

    return 0;
}