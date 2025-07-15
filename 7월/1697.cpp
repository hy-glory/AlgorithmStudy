#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n, k;
	bool visit[100002] = {false,};
	queue<pair<int, int>> q;
	
	cin >> n >> k;
	
	if (n == k) {
		cout << 0;
		return 0;
	}
	if (n > k) {
		cout << n-k;
		return 0;
	}
	
	q.push({n, 0});
	visit[n] = true;
	
	while(!q.empty()){
		int c = q.front().first;
		int d = q.front().second;
		q.pop();

		if (c == k) {
			cout << d;
			break;
		}
		if (c-1 >= 0 && !visit[c-1]) {
			q.push({c-1,d+1});
			visit[c-1] = true;
		}
		if (c+1 <= 100000 && !visit[c+1]) {		
		q.push({c+1, d+1});
		visit[c+1] = true;
		}
		if (2*c <= 100001 && !visit[2*c]) {
		q.push({2*c, d+1});
		visit[2*c] = true;
		}
	}
		
	return 0;
}
