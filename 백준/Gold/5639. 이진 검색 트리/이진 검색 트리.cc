#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
//int sie = 0; //sum identity element : 덧셈 항등원 
//int mie = 1; //multiple identity element : 곱셈 항등원

int l[100001];
int r[100001];
int par[101010];
vector<int> a;

void	put_tree(int idx, int lim)
{
	int big_idx = idx + 1;
	while(big_idx < lim && a[big_idx] < a[idx])++big_idx;
	if (big_idx > idx + 1)
	{
		l[idx] = idx + 1;
		put_tree(idx + 1, big_idx);
	}
	if (big_idx < lim)
	{
		r[idx] = big_idx;
		put_tree(big_idx, lim);
	}
}

void	postorder(int now)
{
	if (l[now] != -1)
		postorder(l[now]);
	if (r[now] != -1)
		postorder(r[now]);
	cout<<a[now]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    a.push_back(0);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
    while (cin>>n)
    {
        a.push_back(n);
    }
	n = a.size();
    put_tree(1, n);
	postorder(1);
	return 0;
}