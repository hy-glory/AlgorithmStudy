#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
int arr[1000002];
int x, g, sum = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> g >> x;
		arr[x] = g;
		sum += g;
	}
	if (K > 500000) {
		cout << sum;
		return 0;
	}
	int left = 0, right = 2*K+1;
	sum = 0;
	for (int i = left; i < right; i++) {
		sum += arr[i];
	}
	int maxSum = sum;
	while(right < 1000002) {
		sum -= arr[left];
		left++;
		sum += arr[right];
		right++;
		maxSum = max(maxSum, sum);
	}
	
	cout << maxSum;
	
	return 0;
}
