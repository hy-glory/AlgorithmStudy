#include <iostream>
#include <vector>
using namespace std;

int N;
bool visit[2000001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	for (int i = 2; i*i <= 2000000; i++) {
		if (!visit[i]) {
			for (int j = i*i; j <= 2000000; j += i) {
				visit[j] = true;
			}
		}
	}
	
	for (int i = 2; i <= 2000000; i++) {
		if (!visit[i]) v.push_back(i);
	}
	
	for (auto vv : v) {
		if (vv >= N) {
			string s = to_string(vv);
			int len = s.length();
			bool isP = true;
			for (int i = 0; i < len/2; i++) {
				if (s[i] != s[len-i-1]) {
					isP = false;
					break;
				}
			}
			if (isP) {
				cout << vv;
				return 0;
			}
		}
	}
	
	return 0;
}