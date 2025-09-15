#include <iostream>
typedef long long ll;

using namespace std;

int N, M, K;
ll sum[1025][1025];
int a1, a2, b1, b2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int n;
			cin >> n;
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + n;
			
		}
	}
	
	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> a1 >> b1 >> a2 >> b2;
		ll result = sum[a2][b2] - sum[a2][b1-1] - sum[a1-1][b2] + sum[a1-1][b1-1];

		cout << result << '\n';
	}
	return 0;
}
