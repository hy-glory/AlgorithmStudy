#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int start = 0, end = K;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += arr[i];
	}
	int maxSum = sum;
	
	while (end < N) {
		sum -= arr[start++];
		sum += arr[end++];
		maxSum = max(maxSum, sum);
	}
	
	cout << maxSum;
	
	return 0;
}
