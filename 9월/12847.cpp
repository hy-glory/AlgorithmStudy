#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;
int N, M;
int T[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
	}
	
	int s = 1, e = M;
	ll sum = 0, maxS = 0;
	for (int i = 1; i <= M; i++) {
		sum += T[i];
	}
	maxS = sum;
	while (e <= N) {
		sum -= T[s];
		s++;
		e++;
		sum += T[e];
		maxS = max(maxS, sum);
	}
	
	cout << maxS;
	
	return 0;
}
