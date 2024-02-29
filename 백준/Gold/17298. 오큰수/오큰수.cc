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

int N;
int arr[1000010];
stack<int>st;
vector<int>ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int mx;
    for (int i = N - 1; i >= 0; i--) {
        if (st.empty()) 
            ans.push_back(-1); 
        else {
            while (arr[i] >= st.top()) {
                st.pop();
                if (st.empty())
                    break ;
            }
            if (st.empty())
                ans.push_back(-1);
            else 
                ans.push_back(st.top());
        }
        st.push(arr[i]);
        
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}