#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;


int solution(int n){
	if (n < 4) return dp[n];
	if (dp[n] != 0) return dp[n];
	
	dp[n] = solution(n-1)+1;
	if (n%3 == 0) {
		dp[n] = min(solution(n/3)+1, dp[n]);
	}
	if (n%2 == 0) {
		dp[n] = min(solution(n/2)+1, dp[n]);
	}
	
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	
	dp.resize(n+1,0);
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	solution(n);
	
	
	cout << dp[n] << endl;
	return 0;
	
}
