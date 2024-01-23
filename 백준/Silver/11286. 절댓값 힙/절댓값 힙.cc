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

class compare {
    public:
        bool operator() (int a, int b) {
            if (abs(a) != abs(b)) return abs(a) > abs(b);
            return a > 0 && b < 0;  
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    priority_queue<int, vector<int>, compare> pq;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        if (num == 0) {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(num);
    }

    return 0;
}