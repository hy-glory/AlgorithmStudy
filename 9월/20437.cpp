#include <iostream>
#include <vector>

using namespace std;
int T, K, minV, maxV;
string W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> W >> K;
		vector<vector<int>> v(26);

		for (int i = 0; i < W.length(); i++) {
			int c = (int)(W[i]-'a');
			v[c].push_back(i);
		}
		
		if (K == 1) {
			cout << 1 << ' ' << 1 << '\n';
			continue;
		}
		minV = 100000, maxV = -1;

		for (int i = 0; i < 26; i++) {
			int vs = v[i].size(); 
			if (vs >= K) {
				int s = 0, e = K-1;
				while(e < vs) {
					minV = min((v[i][e] - v[i][s])+1, minV);
					maxV = max((v[i][e] - v[i][s])+1, maxV);
					s++;
					e++;
				}
			}
		}
		
		if (maxV == -1) {
			cout << -1 << '\n';
		}
		else {
			cout << minV << ' ' << maxV << '\n';
		}
	}
	return 0;
}
