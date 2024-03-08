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
#include <tuple>
#include <climits>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int T;
int N;
// 11의 배수는 홀수 자리의 합과 짝수 자리의 합의 차가 0이거나 11의 배수인 수이다. 다른 방법은 일의 자리 숫자를 제외한 후 남은 숫자에 제외시킨 일의 자리 숫자를 뺀 결과가 0이거나 11의 배수이면 본래의 수도 11의 배수이다.

int check(string s) 
{
    int even = 0;
    int odd = 0; 

    for (int i = 0; i < N; i++) 
    {
        if ((i % 2) == 0)
            even += s[i] - '0';
        else if ((i % 2) == 1)
            odd += s[i] - '0';
    }
    if (abs(even - odd) == 0 || (abs(even - odd) % 11) == 0)
        return 0;
    else if (abs(even) < abs(odd))
        return 1;
    else if (abs(even) > abs(odd))
        return 2;
    else
        return INT_MAX;
}

int chp(string s)
{
    int len = s.length() - 1;
    int hlen = s.length() / 2;
    for (int i = 0; i < hlen; i++) {
        if (s[i] != s[len - i])
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin>>T;

    while (T--)
    {
        cin>>N;
        string s;
        for (int i = 0; i < N; i++) {
            if (i == 0)
                s.push_back('1');
            else if (i == N - 1)
                s.push_back('1');
            else
                s.push_back('0');
        }
        if (s.length() == 1) {
            cout << 0 << '\n'; 
            continue;
        }
        int es = 1; int est = 0; // 홀수인덱스
        int os = 2; int ost = 0; // 짝수인덱스
        int f = -1;
        bool c = false;
        ll sum = 0;
        while (1) 
        {
            f = check(s);
            if (!f) {
                break ;
            }
            else if (f == 2) { // 짝수번째 인덱스 합이 더 큼(홀수를 더해야함)
                if (!(est % 2))
                    s[es]++;
                else
                    s[s.length() - (es + 1)]++;
                if (est % 2)
                    es += 2;
                est += 1;
                if (es > (s.length() - (es + 1)))
                    es = 1;
            } else { // 홀수번째 인덱스 합이 더 큼(짝수를 더해야함) 
                if ((ost % 2) == 0)
                    s[os]++; 
                else if ((ost % 2) == 1)
                    s[s.length() - (os + 1)]++;
                if (ost % 2)
                    os += 2;
                ost += 1;
                if (os > (s.length() - (es + 1)))
                    os = 2;
            }
        }
        if (!c)
            cout << s << '\n';
    }
    return 0;
}