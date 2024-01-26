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

int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break ;
        if (a > b)
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
    }

    return 0;
}