#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> m;
		
		if (m == 0){
			if (!q.empty()) {
				cout << q.top() << '\n';
				q.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		
		else {
			q.push(m);
		}
	}
	return 0;
}
