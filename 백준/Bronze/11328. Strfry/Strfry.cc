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

int T;
string s1;
string s2;
int str1[26];
int str2[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin>>T;
    bool f;
    while (T--)
    {
        cin>>s1>>s2;
        f = false;
        fill(str1, str1+26, 0);
        fill(str2, str2+26, 0);
        for (int i = 0; i < s1.length(); i++)
            str1[s1[i]-'a'] += 1;
        for (int i = 0; i < s2.length(); i++) 
            str2[s2[i]-'a'] += 1;
        for (int i = 0; i < 26; i++) {
            if (str1[i] != str2[i]) {
                cout << "Impossible\n";
                f = true;
                break ;
            }
        }
        if (f) continue;
        cout << "Possible\n";
    }
    return 0;
}