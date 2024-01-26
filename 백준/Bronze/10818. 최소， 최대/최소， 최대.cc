#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{   ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    cout<<mn<<' '<<mx;

    return 0;
}
