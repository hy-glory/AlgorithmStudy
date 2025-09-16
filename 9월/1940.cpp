#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int N, M;
priority_queue<int> pq;
unordered_set<int> us;
int n, count = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		pq.push(n);
		us.insert(n);
	}
	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		if (us.find(top) == us.end()) {
			continue;
		}
		us.erase(top);
		int diff = M - top;
		if (us.find(diff) != us.end()) {
			count++;
			us.erase(diff);
		}
	}
	cout << count;
	return 0;
}
