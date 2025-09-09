#include <iostream>
typedef long long ll;

using namespace std;

int N, n;
int mat[100001];
ll sum[100001];
ll result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		mat[i] = n;
		sum[i] = sum[i-1] + n;
	}
	
	for (int i = N; i >= 2; i--) {
		result += (mat[i] * sum[i-1]);
	}
	
	cout << result;
	
	return 0;
}
