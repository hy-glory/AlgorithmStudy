#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, X;
int arr[100001];
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
	int start = 0, end = N-1;
	int count = 0;
	
	while (start <= end) {
		if (v[start]+v[end] < X) {
			start++;
		}
		else if (v[start]+v[end] > X) {
			end--;
		}
		else {
			count++;
			start++;
		}
	}
	
	cout << count;
	
	return 0;
}
