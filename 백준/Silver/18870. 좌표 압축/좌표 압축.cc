#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int>a(n);
	std::vector<int>b(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < b.size(); i++)
		std::cout << std::lower_bound(a.begin(), a.end(), b[i]) - a.begin() << ' ';
	return 0;
}
