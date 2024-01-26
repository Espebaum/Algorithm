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

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string  s = to_string(n);

    int a[10];
    fill(a, a + 10, 0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - '0' == 9) {
            if (a[9] > a[6])  
                a[6]++;
            else
                a[9]++;
        } else if (s[i] - '0' == 6) {
            if (a[6] > a[9])
                a[9]++;
            else
                a[6]++;
        } else {
            a[s[i] - '0']++;
        }
    }

    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (max < a[i])
            max = a[i];
    }

    cout << max;
    return 0;
}