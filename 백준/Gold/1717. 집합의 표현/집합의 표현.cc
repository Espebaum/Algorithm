#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int	p[1010101];

int	find(int n) //루트를 찾는 함수
{
	if (p[n] < 0)
		return n;
	p[n] = find(p[n]);
	return (p[n]);
}

void	merge(int a, int b) // 두 집합을 합쳐주는 함수
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[b] = a;
}

void	check(int u, int v)
{
	int a, b;
	a = find(u);
	b = find(v);
	if (a == b)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(void)
{
    ios::sync_with_stdio(0);cin.tie(0);
	int	N, M;
	cin >> N >> M;
    fill(p, p + (N+1), -1);

	for(int i = 0; i < M; i++)
	{
		int d, u, v;
		cin>>d>>u>>v;
		if (d == 0)
			merge(u, v);
		else
			check(u, v);
	}
}

// 2 -1 -1 3 2 2 -1 5