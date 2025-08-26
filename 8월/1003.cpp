#include <iostream>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	ll dp0[41] = {0, };
	ll dp1[41] = {0, };

	cin >> T;
	
	dp0[0] = 1;
	dp0[1] = 0;
	dp0[2] = 1;
	
	dp1[0] = 0;
	dp1[1] = 1;
	dp1[2] = 1;
	
	for (int i = 3; i <= 40; i++) {
		dp0[i] = dp0[i-1] + dp0[i-2];
		dp1[i] = dp1[i-1] + dp1[i-2];
	}
	
	int t = 1;
	while (t <= T) {
		int n;
		cin >> n;
		cout << dp0[n] << ' ' << dp1[n] << '\n';
		t++;
	}
	return 0;
}