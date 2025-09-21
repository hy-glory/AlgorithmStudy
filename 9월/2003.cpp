#include <iostream>

using namespace std;
int N, M;
int A[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int start = 0, end = 0;
	int sum = 0, count = 0;
	while (start <= end && start <= N) {
		if (sum == M) {
			count++;
			sum -= A[start];
			start++;
		}
		else if (sum > M) {
			sum -= A[start];
			start++;
		}
		else if (end == N+1) {
			break;
		}
		else {
			sum += A[end];
			end++;
		}
	}
	
	cout << count;
	
	return 0;
}
