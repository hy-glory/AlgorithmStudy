#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	
	cin >> T;
	
	for (int t=0; t<T; t++){
		int n;
		cin >> n;
		
		int arr[2][100001] = {0,};
		int dp[2][100001] = {0, };
		int result = 0;
		
		for (int i = 1; i <= n; i++){
			cin >> arr[0][i];
		}
		for (int i = 1; i <= n; i++){
			cin >> arr[1][i];
		}
		
		if (n == 1){
			result = max(arr[0][1], arr[1][1]);
			cout << result << '\n';
			continue;
		}
		if (n == 2){
			result = max(arr[0][1]+arr[1][2], arr[1][1]+arr[0][2]);
			cout << result << '\n';
			continue;
		}
		
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[0][2] = arr[0][2] + arr[1][1];
		dp[1][2] = arr[1][2] + arr[0][1];
	
		
		if (n >= 3){
			for (int i = 3; i <= n; i++){
				dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[1][i-2]);
				dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
			}
			result = max(dp[0][n], dp[1][n]);
			cout << result << '\n';
		}
	}
	return 0;
}
