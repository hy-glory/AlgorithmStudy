#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
int N, d, k, c;
int D[3000001];
unordered_map<int,int> m;
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
	
	int s = 0, e = k; // [s,e)
	for (int i = s; i < e; i++) {
		m[D[i]]++;
	}
	
	result = m.size();
	if (m.find(c) == m.end()) result++;

	while(s < N) {
		m.find(D[s])->second--;
		if (m.find(D[s])->second == 0) {
			m.erase(D[s]);
		}
		s++;
		m[D[e]]++;
		e++;
		if (e == N) e = 0;

		int size = m.size();
		if (m.find(c) == m.end()) size++;
		result = max(result, size);
	}
	
	
	cout << result;
	
	return 0;
}
