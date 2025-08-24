#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T, N;
	
	cin >> T;
	string strK, strV;
	map<string, int> m;
	int result = 1;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++){
			cin >> strV >> strK;
			if (m.find(strK) != m.end()) {
				m[strK]++;	
			}
			else {
				m.insert({strK, 1});
			}
		}
		for (auto mm : m) {
			int value = mm.second;
			result *= (value+1);
		}
		cout << result-1 << '\n';
		m.clear();
		result = 1;
		
	}
	
	return 0;
}
