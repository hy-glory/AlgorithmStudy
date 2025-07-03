#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp(10,vector<int>(1001, 0));


int solution(int max, int n){
	if (max == 0) return 1;
	if (n == 1) return 1;
	if (dp[max][n] != 0) return dp[max][n];
	
	for (int i = max; i >= 0; i--){
		dp[max][n] += solution(i, n-1);
		dp[max][n] %= 10007;
	}
	return dp[max][n];
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, result = 0;
    
	cin >> n;
			
	for (int i = 0; i <= 9; i++){
		result += solution(i, n);
		result %= 10007;
	}
	
	cout << result;
	
	return 0;	
}


