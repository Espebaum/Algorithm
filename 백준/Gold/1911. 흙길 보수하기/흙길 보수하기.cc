#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

void heapify(vector<pair<int, int> >& arr, int n, int i) 
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<pair<int, int> >& arr) 
{
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; --i)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	int ans = 0;
	vector<pair<int, int> > mud;

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		mud.push_back(make_pair(start, end));
	}

	heapSort(mud);

	int idx = 0;

	for (int i = 0; i < N; i++) {
		if (idx >= mud[i].second)
			continue;

		idx = max(idx, mud[i].first);

		int cnt = (mud[i].second - (idx + 1)) / L + 1;
		ans += cnt;
		idx += L * cnt;
	}

	cout << ans << '\n';

	return 0;
}
