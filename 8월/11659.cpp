#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	int arr[100001];
	int start_sum[100001];
	int end_sum[100001];
	int result;
	int total = 0;
	int count = 0;
	
	cin >> N >> M;
	
	start_sum[1] = 0;
	end_sum[N] = 0;
	for (int n = 1; n <= N; n++) {
		int num;
		cin >> num;
		arr[n] = num;
		if (n < N){
			start_sum[n+1] = start_sum[n] + num;
		}		
		total += num;
	}
	
	for (int n = N; n > 1; n--) {
		end_sum[n-1] = end_sum[n] + arr[n];
	}
	
	for (int n = 1; n <= M; n++){
		int i, j;
		cin >> i >> j;
		
		if (i == j) {
			result = arr[i];
		}
		else {
			result= total - start_sum[i] - end_sum[j];
		}
		cout << result << '\n';
	}
	
	return 0;
}
