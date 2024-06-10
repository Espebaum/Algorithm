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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int A, P;
int arr[1111111];
int number;
int mx = -2147483648;
vector<int> v;
int s;

int recur(int num) 
{
    int result = 0;

    while (num)
    {
        int cur = num % 10;
        result += pow(cur, P);
        num /= 10;
    }   

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> A >> P;
    number = A;
    mx = A;
    arr[number] += 1;
    v.push_back(number); 
    while (1)
    {
        number = recur(number);
        v.push_back(number);
        mx = max(mx, number);
        arr[number] += 1;
        if (arr[number] == 3) {
            s = number;
            break ;
        }
    }
    int ans = 0;
    for (int i = 0; i < mx; i++) {
        if (v[i] == s)
            break ;
        ans++;
    }
    cout << ans;
    return 0;
}