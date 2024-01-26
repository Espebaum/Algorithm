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

int N;
stack< pair<int, int> > s;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    long long sum = 0;
  
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        while (s.size() && s.top().first <= num) {
            s.pop();
        }
        s.push(make_pair(num, s.size()));
        sum += s.top().second;
    }
    cout << sum;
    return 0;
}