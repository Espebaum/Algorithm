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

int a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a; cin >> b; cin >> c;

    int sum = a*b*c;
    string  s = to_string(sum);

    int a[10];
    fill(a, a+10, 0);
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - '0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    return 0;
}