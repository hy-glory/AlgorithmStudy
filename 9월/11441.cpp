#include <iostream>
typedef long long ll;

using namespace std;
int N, M, n, a, b;
ll sum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		sum[i] = sum[i-1] + n;
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << '\n';
	}
	return 0;
}
