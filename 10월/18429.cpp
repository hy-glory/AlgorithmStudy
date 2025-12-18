#include <iostream>

using namespace std;
int N, K;
int list[8];
bool used[8];
int result = 0;

void dfs(int day, int cur) {
	if (day == N) {
		result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			int next = cur + list[i] - K;
			if (next >= 500) {
				used[i] = true;
				dfs(day+1, next);
				used[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	
	dfs(0, 500);
	cout << result;
	
	return 0;
}