#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;
int arr[15001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	
	int left = 0, right = N-1, count = 0;
	while (left < right) {
		if (M > v[left] + v[right]) {
			left++;
		}
		else if (M < v[left] + v[right]) {
			right--;
		}
		else {
			count++;
			left++;
			right--;
		}
	}
	
	cout << count;
	return 0;
}
