#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int A, B, C;
string a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;
    a = to_string(A);
    b = to_string(B);
    // c = to_string(C);

    string ab = a + b;
    int len = ab.length();
    int AB = 0;
    for (int i = 0; i < ab.length(); i++) {
        // cout << ab[i] - '0' << '\n';
        len--;
        AB += (ab[i] - '0') * pow(10, len);
    }
    // cout << "ab: " << ab << '\n';
    cout << A+B-C << '\n';
    cout << AB - C << '\n';

    return 0;
}