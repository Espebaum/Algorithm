#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int	p[1010];

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

int main(void)
{
	int	N, M;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
		p[i] = -1;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	vector<int> cnt(N+1);
	for (int i = 1; i <= N; ++i){
		cnt[find(i)] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans += cnt[i];
	cout << ans;
}

// 2 -1 -1 3 2 2 -1 5