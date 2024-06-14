#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
vector<int>w;
int card[28];
int L[14];
int R[15];

void    mix()
{
    for (int i = 1; i <= 13; i++)
        L[i] = card[i];

    for (int i = 14; i <= 27; i++)
        R[i - 13] = card[i];

    int cur = 1; int rcur = 1; int lcur = 1;
    for (int i = 0; i < w.size(); i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= w[i]; j++) {
                card[cur] = R[rcur];
                cur += 1; rcur += 1;
            }
        }
        else {
            for (int k = 1; k <= w[i]; k++) {
                card[cur] = L[lcur];
                cur += 1; lcur += 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    cin.ignore();

    for (int i = 1; i <= 27; i++)
        card[i] = i;

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        istringstream   iss(s);
        int number;
        while (iss >> number)
            w.push_back(number);
        mix();
        w.clear();
    }

    for (int i = 1; i <= 27; i++)
        if (card[i] == 1)
            cout << i << '\n';
            
    return 0;
}