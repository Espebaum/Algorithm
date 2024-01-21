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
using namespace std;

string  f;
vector<char>    op;
vector<int>     num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> f;
    stringstream   ss;
    ss << f;
    int nu;
    ss >> nu;
    num.push_back(nu);

    while (1)
    {
        char    c;
        int     n;
        ss >> c;
        if (ss.eof())
            break ;
        op.push_back(c);
        ss >> n;
        num.push_back(n);
    }

    int sum = num[0];
    int i = 0;
    int j = 1;

    while (i < op.size())
    {
        if (op[i] == '+') {
            sum += num[j];
            i++;
            j++;
        } else if (op[i] == '-') {
            int tmp = i;
            int t_sum = num[j];
            tmp++;
            j++;
            while (op[tmp] == '+') {
                t_sum += num[j];
                tmp++;
                j++;
            }
            sum -= t_sum;
            i = tmp;
        }
    }
    cout << sum;
    return 0;
}