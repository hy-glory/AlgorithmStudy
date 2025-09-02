#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, K;
	priority_queue<int> pq;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}
	
	int goal = K;
	int count = 0;
	while (!pq.empty()) {
		int front = pq.top();
		pq.pop();
		if (front > goal) continue;
		count += goal/front;
		goal %= front;
		if (goal == 0) break;
	}
	cout << count;
	return 0;
}
