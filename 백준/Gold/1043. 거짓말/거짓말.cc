#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int p[52];
vector<int> know;
vector<int> party[52]; // 변경된 부분

int Find(int x) {
    if (p[x] == x) return x;
    return x = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    while (k--) {
        int t;
        cin >> t;
        know.push_back(t);
    }

    for (int i = 1; i <= n; i++) 
        p[i] = i;

    int p, num, prev;
    for (int i = 0; i < m; i++)
    {
        int p; cin >> p;
        for (int j = 0; j < p; j++) {
            if (j >= 1) {
                prev = num; cin >> num;
                Union(prev, num);
            }
            else 
                cin >> num;
            party[i].push_back(num);
        }
    }

    int res = m;
    for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int j = 0; j < party[i].size(); j++) 
        {
            if (flag) 
                break;
            for (int k = 0; k < know.size(); k++) 
            {
                if (Find(party[i][j]) == Find(know[k])) 
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) 
            res--;
    }
    cout << res;
    return 0;
}
