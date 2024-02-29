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

string s1, s2;
int str1[26];
int str2[26];
vector<int>diff;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin>>s1>>s2;
    for (int i = 0; i < s1.length(); i++)
        str1[s1[i]-'a']++;
    for (int i = 0; i < s2.length(); i++)
        str2[s2[i]-'a']++;
    for (int i = 0; i < 26; i++){
        if (str1[i] != str2[i])
            diff.push_back(i);
    }
    // for (int i = 0; i < diff.size(); i++) {
        // cout << diff[i] << ' '; 
    // }
    // cout << '\n';
    for (int i = 0; i < diff.size(); i++) {
        ans += abs(str1[diff[i]]-str2[diff[i]]);
    }
    cout << ans;
    return 0;
}