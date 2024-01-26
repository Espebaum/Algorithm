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

long long n, sum;
vector<int> v;
long long bj, bm;

long long gcd(int a, int b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


void    calculate(long long num, long long den, long long upp)
{
    if (bj == 0) {
        long long n = num * den + upp;
        long long d = den;

        long long gd = gcd(n, d);

        if (gd != 1)
        {
            while (n % gd == 0) {
                n /= gd;
                d /= gd;
            }
        }

        cout << n << '/' << d;
        return ;
    }
    
    bj -= 1;
    long long n_num, n_den, n_upp;

    n_num = v[bj];
    n_den = num * den + upp;
    n_upp = den;
    calculate(n_num, n_den, n_upp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    
    if (v.size() == 1) {
        cout << v[0] << '/' << 1;
        return 0;
    }


    bj = v.size() - 2;
    bm = v.size() - 1;

    calculate(v[bj], v[bm], 1);

    return 0;
}