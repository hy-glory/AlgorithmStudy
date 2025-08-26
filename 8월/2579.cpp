#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	int arr[301] = {0,};
	int dp[301] = {0,};
	
	cin >> N;
	
	for (int i = 1; i<=N; i++) {
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	if (N >=2) dp[2] = dp[1] + arr[2];
	if (N >=3) dp[3] = max(dp[1], arr[2]) + arr[3];
	for (int n =4; n <= N; n++) {
		dp[n] = max(dp[n-2], dp[n-3] + arr[n-1]) + arr[n];
	}
	
	cout << dp[N];
	
	return 0;
}