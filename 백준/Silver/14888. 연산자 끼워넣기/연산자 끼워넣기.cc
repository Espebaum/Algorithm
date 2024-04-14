#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int arr[110];
int order[110];
int isused[110];
// 0plus, 1minus, 2mul, 3div
vector<char>ops;
vector<int>ans;

void    operation()
{
    int value = arr[0];
    char myorder[110];

    for (int i = 0; i < ops.size(); i++) {
        myorder[i] = ops[order[i]];
    }

    // for (int i = 0; i < ops.size(); i++) {
    //     cout << myorder[i] << ' ';
    // }   cout << '\n';

    for (int i = 0; i < ops.size(); i++) 
    {
        if (myorder[i] == '+')
            value += arr[i + 1];
        else if (myorder[i] == '-')
            value -= arr[i + 1];
        else if (myorder[i] == 'x')
            value *= arr[i + 1];
        else if (myorder[i] == '/')
            value /= arr[i + 1];
    }
    ans.push_back(value);
}


void    solve(int k)
{
    if (k == ops.size()) {

        // for (int i = 0; i < ops.size(); i++) {
        //     cout << order[i] << ' ';
        // } cout << '\n';

        operation();
        return ;
    }

    for (int i = 0; i < ops.size(); i++) {
        if (!isused[i]) {
            order[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++) {
        int num; cin >> num;
        if (i == 0)
            for (int j = 0; j < num; j++)
                ops.push_back('+');
        else if (i == 1)
            for (int j = 0; j < num; j++)
                ops.push_back('-');
        else if (i == 2)
            for (int j = 0; j < num; j++)
                ops.push_back('x');
        else
            for (int j = 0; j < num; j++)
                ops.push_back('/');
    }

    solve(0);

    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << ' ';
    // cout << '\n';
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << '\n' << ans[0];

    return 0;
}