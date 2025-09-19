#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	
	int start = 0;
	int end = 0;
	int count = 5;
	
	while (start <= end && end < N) {
		if (v[end]-v[start] > 4) {
			start++;
		}
		else if (v[end]-v[start] < 4) {
			int diff = end - start + 1;
			count = min(count, 5-diff);
			end++;
		}
		else {
			int diff = end - start + 1;
			count = min(count, 5-diff);
			start++;
		}
	}
	
	cout << count;
	
	return 0;
}
