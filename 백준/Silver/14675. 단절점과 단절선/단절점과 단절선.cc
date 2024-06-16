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

int N,M,p,c,t,k;
vector<int>adj[100100];
int vis[100100];
int r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);  
    }
    
    cin >> M ;
    for (int i = 0; i < M; i++)
    {
        cin >> t >> k;
        if (t == 2) {
            cout << "yes\n";            
        }
        else {
            if (adj[k].size() >= 2)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
    
    return 0;
}