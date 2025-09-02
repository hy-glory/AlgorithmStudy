#include <iostream>
#define MOD 10007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	int dp[1001];
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	if (n > 3) {
		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i-1] + dp[i-2])%MOD;
		}
	}
	
	cout << dp[n];
	
	return 0;
}
