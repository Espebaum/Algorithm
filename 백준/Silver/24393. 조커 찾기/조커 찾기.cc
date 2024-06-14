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
#include <sstream>
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
    for (int i = 1; i <= 13; i++) {
        L[i] = card[i];
        card[i] = 0;
    }
    for (int i = 14; i <= 27; i++) {
        R[i - 13] = card[i];
        card[i] = 0;
    }

    // cout << "L : ";
    // for (int i = 1; i <= 13; i++) {
    //     cout << L[i] << ' ' ;
    // } cout << '\n';

    // cout << "R : ";
    // for (int i = 1; i <= 14; i++) {
    //     cout << R[i] << ' ' ;
    // } cout << "\n\n";

    // cout << "W: ";
    // for (int i = 0; i < w.size(); i++) {
    //     cout << w[i] << ' ';
    // } cout << "\n\n";

    int cur = 1;
    int rcur = 1;
    int lcur = 1;
    for (int i = 0; i < w.size(); i++) {
        //i == 짝수 오른쪽에서 Ai 장
        if (i % 2 == 0) {
            for (int j = 1; j <= w[i]; j++) {
                card[cur] = R[rcur];
                cur += 1;
                rcur += 1;
            }
        }
        //i == 홀수 왼쪽에서 Ai 장
        else {
            for (int k = 1; k <= w[i]; k++) {
                card[cur] = L[lcur];
                cur += 1;
                lcur += 1;
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

    // for (int i = 1; i <= 27; i++) {
    //     cout << card[i] << ' ';
    // } cout << "\n\n";

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

    for (int i = 1; i <= 27; i++) {
        // cout << card[i] << ' ';
        if (card[i] == 1) {
            cout << i << '\n';
        }
    }

    return 0;
}