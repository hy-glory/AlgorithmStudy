#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, X;
int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	cin >> X;
	
	sort(v.begin(), v.end());
	int left = 0, right = N-1;
	int count = 0;
	
	while (left < right) {
		if (v[left]+v[right] < X) {
			left++;
		}
		else if (v[left]+v[right] > X) {
			right--;
		}
		else {
			count++;
			left++;
		}
	}
	
	cout << count;
	
	return 0;
}