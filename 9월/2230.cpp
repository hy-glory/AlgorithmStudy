#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	
	if (M == 0) {
		cout << 0;
		return 0;
	}
	
	sort(v.begin(), v.end());
	
	int l = 0, r = 0;
	int result = 2000000001;
	while(l < N && r < N) {
		if (v[r]-v[l] < M) {
			r++;
		}
		else if (v[r]-v[l] > M) {
			result = min(result, abs(v[r]-v[l]));
			l++;
			r = l;
		}
		else {
			result = M;
			break;
		}
	}
	cout << result;
	
	return 0;
}
