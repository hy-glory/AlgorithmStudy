#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	priority_queue<int> q;
	cin >> N;
	for (int i=1; i<=N; i++) {
		int n;
		cin >> n;
		q.push(n);
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result += q.top()*i;
		q.pop();
	}
	
	cout << result;
	
	return 0;
}