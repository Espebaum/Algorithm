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

void    under_ten()
{
    if (N == 3 || N == 5)
        cout << 1;
    else if (N == 4 || N == 7)
        cout << -1;
    else if (N== 6 || N == 8)
        cout << 2;
    else
        cout << 3;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int tmp = N;
    
    if (tmp < 10) {
        under_ten();
        return 0;
    }
    else
    {
        if (tmp % 5 == 0)
            cout << tmp / 5;
        else if (tmp % 5 == 1 || tmp % 5 == 3)
            cout << tmp / 5 + 1;
        else if (tmp % 5 == 2 || tmp % 5 == 4)
            cout << tmp / 5 + 2;
    }
    return 0;
}