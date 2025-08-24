#include <iostream>
#define ll long long
using namespace std;
ll dp[101] = {0,};

ll sol(int n) {
	if (n < 7) return dp[n];
	if (dp[n] != 0) return dp[n];
	dp[n] = sol(n-1) + sol(n-5);
	return dp[n];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T, N;
	cin >> T;
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		sol(N);
		cout << dp[N] << '\n';
	}
	
	return 0;
}
